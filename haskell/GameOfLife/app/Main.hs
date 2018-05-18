module Main where

import Lib
import System.Random
--import Control.Concurrent (threadDelay)

main :: IO ()
main = do
    gen <- newStdGen
    let game = makeRandomGame gen (30,50)
    playTurn game



playTurn game = do
    showGame game
    let newGame = nextGame game
    --threadDelay 1000
    str <- getLine
    playTurn newGame

