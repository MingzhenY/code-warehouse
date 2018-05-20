import Data.List
import Data.List.Split
import Data.Char

type Grid a = [[a]]

main :: IO ()
main = do
    content <- getContents
    let ls = lines content
        n_m :: [Int]
        n_m = map read $ splitOn " " $ head ls
        grid = tail ls
        grid_sum = gridSum grid
        resultPair = zipWith zip grid_sum grid
        pass = all checkValid resultPair
    --putStrLn.unlines $ map (concat.(map show)) $ grid_sum
    if pass then
        putStrLn "YES"
    else
        putStrLn "NO"

checkValid :: [(Int,Char)] -> Bool
checkValid = all pairValid
pairValid :: (Int,Char) -> Bool
pairValid (0,'.') = True
pairValid (_,'*') = True
pairValid (x,y) = x + (ord '0') == ord y

gridSum grid =
    let x = length grid 
        y = length $ head grid
        boardCore =(map.map) (\ch -> if ch== '*' then 1::Int else 0::Int) grid 
        boardShifts = [gridShift boardCore p | p <- nearCoords]
        zeroGrid = take (x+2) . repeat $ take (y+2) . repeat $ (0::Int)
        boardSum = init.tail $ foldr ((zipWith.zipWith) (+)) zeroGrid boardShifts
    in map (init.tail) boardSum


nearCoords :: [(Int,Int)]
nearCoords = [(1,0)
             ,(1,1)
             ,(0,1)
             ,(-1,1)
             ,(-1,0)
             ,(-1,-1)
             ,(0,-1)
             ,(1,-1)
             ]

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


