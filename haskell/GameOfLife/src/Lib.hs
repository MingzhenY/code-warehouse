module Lib
    ( Game(Game,gameXY,gameBoard)
    , Grid
    , makeRandomGame
    , makeRandomGrid
    , showGame
    , nextGame
    , gridShift
    , showGrid
    ) where

import System.Random
import Data
--import Data.List

type Grid a = [[a]]

data Game = Game {
            gameXY :: (Int,Int)
        ,   gameBoard :: Grid Int
        }
        deriving (Show,Eq)


makeRandomGame :: StdGen -> (Int, Int)-> Game
makeRandomGame gen (x,y) = 
    let gridInf = makeRandomGrid gen
        gridXY = take x $ map (take y) gridInf
        blankLine = take (y+2) $ repeat 0
        grid =  [blankLine]
                ++ (map (\line ->  [0] ++ line ++ [0]) gridXY)
                ++ [blankLine]
    in Game (x,y) grid

showGame :: Game -> IO()
showGame (Game _ gb) = showGrid gb

showGrid :: Grid Int -> IO()
showGrid = putStrLn . unlines . ((map.map) (\n -> if n == 1 then 'O' else ' '))

makeRandomGrid :: RandomGen t => t -> Grid Int
makeRandomGrid gen = 
    let (gen1, gen2) = split gen
        row = randomRs (0::Int, 1::Int) gen1
    in row : makeRandomGrid gen2

nextGame :: Game -> Game
nextGame game@(Game (x,y) gb) = 
    let boardCore = map (tail.init) $ (tail.init) gb
        boardShifts = [gridShift boardCore p | p <- nearCoords]
        zeroGrid = take (x+2) . repeat $ take (y+2) . repeat $ (0::Int)
        boardSum = foldr ((zipWith.zipWith) (+)) zeroGrid boardShifts
        boardZip = zipWith zip gb boardSum
        alive :: (Int,Int)->Int
        alive (s,2) = s
        alive (_,3) = 1
        alive _ = 0
        newGrid = (map.map) alive boardZip
    in game {gameBoard = newGrid}

gridShift :: Grid Int -> (Int, Int) -> Grid Int
gridShift grid _ | length grid == 0 = []
gridShift _ (x,y) | not.elem (x,y) $ nearCoords = []
gridShift gridCore (x,y) =
    let --oldx = length grid
        oldy = length.head $ gridCore
        rowUp = 1 + x
        rowDown = 1 - x
        colLeft = 1 + y
        colRight = 1 - y
        row_Up = take rowUp . repeat $ take (oldy + 2) . repeat $ (0::Int)
        row_Down = take rowDown . repeat $ take (oldy + 2) . repeat $ (0::Int)
        col_Left = take colLeft $ repeat (0::Int)
        col_Right = take colRight $ repeat (0::Int)
    in  row_Up
        ++  (map (\line -> col_Left ++ line ++ col_Right) gridCore)
        ++ row_Down
        





