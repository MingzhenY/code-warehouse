import System.IO
import Control.Monad  
import Data.List 

myGCD ::(Integral a)=>[a]->a
myGCD =foldl (\ans x-> gcd ans x) 0

main = do
	num<-getLine
	let n=read num
	numbers <- forM [1..n] (\a ->do
	tempNumStr<-getLine
	return tempNumStr)
	print.myGCD.(map read) $ numbers