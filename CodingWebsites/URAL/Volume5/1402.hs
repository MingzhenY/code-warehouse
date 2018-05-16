import System.IO
import Control.Monad  
import Data.List 

fac ::Integer->Integer
fac n
    |n==0 =1
    |otherwise=(*n).fac $(n-1)

myA ::Integer->Integer->Integer
myA m n=div (fac m) (fac (m-n)) 

myFunc::Integer->Integer
myFunc x
    |x==1 = 0
    |otherwise=sum (map (myA x) [2..x])

main = do
   n<-fmap read getLine
   print.myFunc $ n
   
