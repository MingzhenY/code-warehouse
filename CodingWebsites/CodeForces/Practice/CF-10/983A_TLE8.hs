import Data.List
import Data.List.Split
import Data.Maybe

type State = (Integer,Integer,Integer,Integer)

-- Note: TLE on Test 8

main :: IO ()
main = do
    content <- getContents
    let inputs :: [[Integer]]
        inputs = map (map read . splitOn " ") $ tail . lines $ content
    putStr.unlines $ map checkState inputs
    

checkState :: [Integer] -> String
checkState [0,q,b] = "Finite"
checkState [p,q,b] =
        let state = (p,p,q,b)
            pass = isInf state $ nextState state
        in  if pass then "Infinite" else "Finite"
checkState _ = "Error"


isInf :: State -> Maybe State -> Bool
isInf _ Nothing = False
isInf (p1,p2,_,_) (Just new_s@(np1,np2,_,_))
        | np1 == np2 = np1 /= 0
        | otherwise = isInf new_s $ nextState new_s
    


nextState :: State -> Maybe State
nextState (0, _, _, _) = Nothing
nextState (_, 0, _, _) = Nothing
nextState (p1, p2, q, b) = 
            let f = (`mod` q).(*b)
                new_p1 = f p1
                new_p2 = f.f $ p2
            in Just (new_p1,new_p2,q,b)





