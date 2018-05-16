import System.IO
import Control.Monad  
import Data.List 

calculate ::Integral a=>a->a
calculate x
    |mod x 2 ==0 = div x 2
    |otherwise =negate.(`div` 2).(+1) $ x

main=do
    ans <- fmap (calculate.read) getLine
    print ans