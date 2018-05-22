import Data.List
import Data.List.Split
import Data.Maybe

--Note: TLE9

main :: IO ()
main = do
    content <- getContents
    let inputs :: [[Integer]]
        inputs = map (map read . splitOn " ") $ tail . lines $ content
    putStr.unlines $ map checkState inputs
    

checkState :: [Integer] -> String
checkState [0,q,b] = "Finite"
checkState [p,q,b] =
        let gcd_pq = gcd p q
            _q = div q gcd_pq
            pass = isInf _q b
        in  if pass then "Infinite" else "Finite"
checkState _ = "Error"


-- gcd(p,q) = 1
isInf :: Integer -> Integer -> Bool
isInf q b = 
    let gcd_qb = gcd q b
        _q = div q gcd_qb
    in if gcd_qb == 1 
        then
            if q == 1
                then False
                else True
        else 
            isInf _q gcd_qb






