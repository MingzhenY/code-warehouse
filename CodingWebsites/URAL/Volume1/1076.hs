import System.IO
import Control.Monad  
import Data.List 

type Matrix = [[Integer]];
mul :: Matrix -> Matrix -> Matrix
mul a b = [[(sum.zipWith (*) x) y|y<-transpose b]|x<-a]

sumOfMatrix a = sum [sum x|x<-a]

m1 = [[62,41,86,94],[73,58,11,12],[69,93,89,88],[81,40,69,13]]
