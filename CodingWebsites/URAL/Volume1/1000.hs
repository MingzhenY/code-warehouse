import System.IO
import Control.Monad  
import Data.List 


main = do
    numStr'<-getLine
    let numStr=numStr'
    mapM_ print [ sum $ map read $ words numStr]