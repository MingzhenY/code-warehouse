import Data.Char
-- Reading "Category theory for programmers" Chapter 4
-- A way to add logs on top of functions
-- And to combine these functions easily


-- A writer type to store result of a function and a log message
type Writer a = (a, String)

-- A function to combine functions
(>=>) :: (a -> Writer b) -> (b -> Writer c) -> (a -> Writer c)
m1 >=> m2 = \x ->
    let (y, s1) = m1 x
        (z, s2) = m2 y
    in (z, s1 ++ s2)

-- The identity morphism
return :: a -> Writer a 
return x = (x, "")


upCase :: String -> Writer String 
upCase s = (map toUpper s, "upCase ")

toWords :: String -> Writer [String] 
toWords s = (words s, "toWords ")

process :: String -> Writer [String]
process = upCase >=> toWords



