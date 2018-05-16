import System.IO
import Control.Monad  
import Data.List 

main =do
	numStr'<-getLine
	let numStr=numStr'
	let n=sum $ map read $ words numStr
	if (mod n 5)==0 && (n>0)
	then mapM_ print $  [div n 5]
	else putStrLn "-1" 