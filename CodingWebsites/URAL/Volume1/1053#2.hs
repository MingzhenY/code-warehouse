import System.IO
import Control.Monad  
import Data.List 

myGCD ::(Integral a)=>[a]->a
myGCD []=0
myGCD [x]=x
myGCD xs=gcd  (myGCD.fst $ k) (myGCD.snd $ k)
    where n=length xs
          k=splitAt (div n 2) xs

main = do
	num<-getLine
	let n=read num
	numbers <- forM [1..n] (\a ->do
	tempNumStr<-getLine
	return tempNumStr)
	print.myGCD.(map read) $ numbers