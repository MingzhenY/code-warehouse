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
    , Game(gameGrid,gameWords)
    , makeGame
    , totalWords
    , score
    , playGame
    , formatGame
    , completed
    , makeRandomGrid
    , fillInBlanks
    , formatGameGrid
    ) where

import Data.List (isInfixOf, transpose)
import Data.Maybe (catMaybes,listToMaybe)
import qualified Data.Map as M
import System.Random
import Data.Char (toLower)

data Game = Game { 
            gameGrid :: Grid Cell ,
            gameWords :: M.Map String (Maybe [Cell])
        }
    deriving Show

type Grid a = [[a]]
data Cell = Cell (Integer,Integer) Char 
          | Indent
    deriving (Eq, Ord, Show)

makeGame :: Grid Char -> [String] -> Game
makeGame grid words =
    let gwc = gridWithCoords grid
        tuplify word = (word, Nothing)
        list = map tuplify words
        dict = M.fromList list
    in Game gwc dict

totalWords :: Game -> Int
totalWords game = length . M.keys $ gameWords game

score :: Game -> Int
score game = length . catMaybes . M.elems $ gameWords game

completed :: Game -> Bool
completed game = score game == totalWords game

playGame :: Game -> String -> Game
playGame game word | not $ M.member word (gameWords game) = game
playGame game word =
    let grid = gameGrid game
        foundWord = findWord grid word
    in case foundWord of 
            Nothing -> game 
            Just cs -> 
                let dict = gameWords game 
                    newDict = M.insert word foundWord dict
                in game {gameWords = newDict}

formatGame :: Game -> String
formatGame game = formatGameGrid game
                    ++ "\n\n"
                    ++ (show $ score game)
                    ++ "/"
                    ++ (show $ totalWords game)

makeRandomGrid gen = 
    let (gen1, gen2) = split gen
        row = randomRs ('A','Z') gen1 
    in row : makeRandomGrid gen2


fillInBlanks gen grid =
    let r = makeRandomGrid gen 
        fill '_' r = r 
        fill c _ = c
    in zipOverGridWith fill grid r

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

formatGameGrid :: Game -> String
formatGameGrid game =
    let grid = gameGrid game
        dict = gameWords game :: M.Map String (Maybe [Cell])
        cellSet = concat . catMaybes . M.elems $ dict
        formatCell cell =
            let char = cell2char cell 
            in if cell  `elem` cellSet then char else toLower char
        charGrid = mapOverGrid formatCell grid 
    in unlines charGrid 

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

