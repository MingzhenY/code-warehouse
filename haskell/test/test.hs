
import Control.Monad (guard)
import Data.List (transpose)

data Cell = Cell (Integer,Integer) Char deriving (Eq, Ord, Show)

coords = do
    row <- [0..7]
    return $ do
        col <- [0..7]
        return (row,col)

coords1 = [[(row,col)|col<-[0..7]]|row<-[0..7]]

zipOverGrid = zipWith zip
zipOverGridWith = zipWith.zipWith
coords2 = zipOverGrid rows8 cols8

cols = repeat [0..]
rows = map repeat [0..]
coordsInf = zipOverGrid rows cols

repeat8 = take 8 . repeat
cols8 = repeat8 [0..7]
rows8 = map repeat8 [0..7]

grid = [ "__C________R___"
       , "__SI________U__"
       , "__HASKELL____B_"
       , "__A__A_____S__Y"
       , "__R___B___C____"
       , "__PHP____H_____"
       , "____S_LREP_____"
       , "____I__M_Y__L__"
       , "____L_E__T_O___"
       , "_________HB____"
       , "_________O_____"
       , "________CN_____"
       ]

og :: Show a => [a] -> IO()
og = putStrLn . unlines . map show 


div2 x = x `mod` 2 == 0

-- List monad notation
mapped = do
    i <- [0..9]
    return (i * 2)

filtered = do
    i <- [0..9]
    guard (div2 i)
    return i

