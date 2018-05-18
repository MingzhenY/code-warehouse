module Lib
    ( formatGrid
    , outputGrid
    , findWord
    , findWords
    , findWordInLine
    , getLines
    , diagonalFromGrid
    , skew
    , zipOverGrid
    , zipOverGridWith
    , gridWithCoords
    , coordsGrid
    , cell2char
    , Cell(Cell,Indent)
    , findWordInCellLinePrefix
    ) where

import Data.List (isInfixOf, transpose)
import Data.Maybe (catMaybes,listToMaybe)

type Grid a = [[a]]
data Cell = Cell (Integer,Integer) Char 
          | Indent
    deriving (Eq, Ord, Show)

zipOverGrid :: Grid a -> Grid b -> Grid (a,b)
zipOverGrid = zipWith zip

zipOverGridWith :: (a->b->c) -> Grid a -> Grid b -> Grid c
zipOverGridWith = zipWith.zipWith

coordsGrid :: Grid (Integer, Integer)
coordsGrid = 
    let cols = repeat [0..]
        rows = map repeat [0..]
    in zipOverGrid rows cols

gridWithCoords grid = zipOverGridWith Cell coordsGrid grid

mapOverGrid:: (a->b) -> Grid a -> Grid b
mapOverGrid = map . map

formatGrid :: Grid Cell -> String
formatGrid = unlines . mapOverGrid cell2char
  

outputGrid :: Grid Cell -> IO()
outputGrid = putStrLn.formatGrid

cell2char :: Cell -> Char
cell2char (Cell _ c) = c
cell2char Indent = '?'

cells2string = map cell2char

findWords :: Grid Cell -> [String] -> [[Cell]]
findWords grid words =
    let foundWords = map (findWord grid) words
    in catMaybes foundWords

getLines :: Grid Cell -> [[Cell]]
getLines grid =
  let horizontal = grid
      vertical = transpose horizontal
      diagonal = diagonalize horizontal
      diagonal' = diagonalize $ map reverse horizontal
      lines = horizontal ++ vertical ++ diagonal ++ diagonal'
  in lines ++ (map reverse lines)

findWord :: Grid Cell -> String -> Maybe [Cell]
findWord grid word = 
    let lines = getLines grid
        foundWords = map (findWordInLine word) lines
    in listToMaybe (catMaybes foundWords)

findWordInLine:: String -> [Cell] -> Maybe [Cell]
findWordInLine _ [] = Nothing
findWordInLine word line = 
    let found = findWordInCellLinePrefix [] word line
    in case found of
        Nothing -> findWordInLine word (tail line)
        cs@(Just _) -> cs

findWordInCellLinePrefix :: [Cell] -> String -> [Cell] -> Maybe [Cell]
findWordInCellLinePrefix acc (x:xs) (c:cs) | x == cell2char c
    = findWordInCellLinePrefix (c : acc) xs cs
findWordInCellLinePrefix acc [] _ = Just $ reverse acc
findWordInCellLinePrefix _ _ _ = Nothing

diagonalize :: Grid Cell -> Grid Cell
diagonalize = transpose.skew

skew:: Grid Cell -> Grid Cell
skew [] = []
skew (l:ls) = l : (map indent $ skew ls)
    where indent line = Indent : line

-- my implementation of diagonalize
-- so much longer than diagonalize 
diagonalFromGrid :: Grid Cell -> Grid Cell
diagonalFromGrid grid =
    let x = length grid
        y = length $ grid !! 0
        diag1 = [[grid!!(sum-i)!!i|i<-[0..sum],sum-i >= 0,i<y]|sum<-[0..x-1]]
        diag2 = [[grid!!(x-1-i)!!(sum+i)|i<-[1..(y-sum)],x-i-1 >= 0,sum+i<y]|sum<-[0..y-1]]
    in diag1 ++ diag2

