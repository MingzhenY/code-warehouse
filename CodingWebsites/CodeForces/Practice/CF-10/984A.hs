import Data.List
import Data.List.Split


main = do
    nstr <- getLine
    let n = read nstr :: Int
    line <- getLine
    let ints = map (read::String->Int) $ splitOn " " line
    let sints = sort ints
    print (sints, n, (n-1) `div` 2)
    print (sints!!0)
    print (sints!!1)
    print (sints!!2)
    putStrLn.show $ sints !! ((n - 1) `div` 2)
