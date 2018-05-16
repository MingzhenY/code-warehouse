import System.IO
import Control.Monad  
import Data.List 


caculate ::(Integral a)=>a->a
caculate x = div  (x*(x-1)) 2

upInt :: (Integral a)=> a->a->a
upInt x y 
	| mod x y ==0  = div x y
	| otherwise = (+1).(div x)$ y

countMin ::(Integral a)=>a->a->a
countMin x y =(mod x y) * (caculate $ upInt x y) + (y - (mod x y)) * (caculate $ div x y)

main = do
	numStr'<-getLine
	let numStr=numStr'
	let num = map read $ words numStr
	let n= head num;
	let m= head.tail $ num
	let maxNum = caculate  (n-(m-1))
	let minNum = countMin n m
	mapM_ putStrLn $ [unwords ( map show [minNum ,maxNum])]
	