import System.IO
import Control.Monad  
import Data.List 

namee=zip ["Slytherin","Hufflepuff","Gryffindor","Ravenclaw"] [1..]

sortHat::[(String,Integer)]->String->Integer
sortHat [] _ = 0
sortHat (x:xs) str 
    |str == fst x =snd x
    |otherwise = sortHat xs str

myInsert::String->String->[[String]]->[[String]]
myInsert str sname (a:b:c:d:[])
    |n==1 =(str:a):b:c:d:[]
    |n==2 =a:(str:b):c:d:[]
    |n==3 =a:b:(str:c):d:[]
    |n==4 =a:b:c:(str:d):[]
    |otherwise =a:b:c:d:[]
    where n=sortHat namee  sname

myFunc ::[(String,String)]->[[String]]
myFunc []=[[],[],[],[]]
myFunc (x:xs)=myInsert (fst x) (snd x) (myFunc xs)

main=do
    n<-fmap read  getLine
    ans<-forM [1..n] (\a->do
        name<- getLine
        sname<- getLine
        return (name,sname))
    let finalAns=myFunc ans
    putStrLn "Slytherin:"
    mapM_ putStrLn (finalAns !! 0)
    putStrLn "\nHufflepuff:"
    mapM_ putStrLn (finalAns !! 1)
    putStrLn "\nGryffindor:"
    mapM_ putStrLn (finalAns !! 2)
    putStrLn "\nRavenclaw:"
    mapM_ putStrLn (finalAns !! 3)





