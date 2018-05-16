import System.IO
import Control.Monad  
import Data.List 
import Data.Char
import Data.Ratio

myCount :: String->[Integer]
myCount []=[0,0,0,0,0,0,0,0,0]
myCount (x:xs)
    |x=='0' =myCount []
    |otherwise =(fst k) ++[(+1).head.snd $ k] ++ (tail.snd $ k)
    where  dx=(digitToInt x) -1
           k=splitAt dx $ myCount xs

sq=sqrt 0.5
myPair=[(-sq,-sq),(0,-1),(sq,-sq),(-1,0),(0,0),(1,0),(-sq,sq),(0,1),(sq,sq)]::[(Double,Double)] 

myMul::(Double,Double)->Integer->(Double,Double)
myMul x k=((fromInteger k)*(fst x),(fromInteger k)*(snd x))

myPlus::(Double,Double)->(Double,Double)->(Double,Double)
myPlus x y=((fst x)+(fst y),(snd x)+(snd y))

myCal::[(Double,Double)]->[Integer]->(Double,Double)
myCal _ []=(0.0,0.0)
myCal (x:xs) (y:ys) =myPlus (myMul x y) (myCal xs ys)

main = do
    str <-getLine
    print $ myCal myPair $ myCount str         
        
        
        
        
        

