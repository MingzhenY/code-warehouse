import System.IO
import Control.Monad  
import Data.List 

main = do 
    ans <- fmap (((map sqrt ). reverse ).((map read).words.unwords.lines) ) getContents
    mapM_ print ans
    main