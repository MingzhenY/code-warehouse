import System.IO
import Control.Monad  
import Data.List 
import Data.Maybe

main = do
	number <-getLine
	numberStr <- getLine
	let n=number
	let numberString=numberStr
	let ori=map read (words numberString)
	let k=partition (\a ->mod a 2 ==0) ori
	if (==1).length.fst $ k 
	then mapM_ print $ [1+ ( head $ maybeToList (elemIndex (head $ fst k) ori))]
	else mapM_ print $ [1+ ( head $ maybeToList (elemIndex (head $ snd k) ori))]
	