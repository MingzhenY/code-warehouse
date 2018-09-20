-- Reading "A Tutorial Introduction to the Lambda Calculus"  by Raul Rojas
-- doing experiments here


-- numbers will be defined as functions using the following approach
-- 0 = (\x y -> y)
-- 1 = (\x y -> x (y) )
-- 2 = (\x y -> x (x (y)) )
-- With this defenition 3fa = f(f(f(a)))
--define from 0 to 100 for easy testing
--myInt ::Integer->(a->a)->a->a
--myInt :: (Num a, Ord a) => a -> (c -> c) -> c -> c
myInt 0 = (\x y -> y)
myInt 1 = (\x y -> x y)
myInt 2 = (\x y -> (x.x) y)  
myInt 3 = (\x y -> (x.x.x) y)
myInt n 
    | n < 0 = undefined
    | n > 100 = undefined
    | n <= 100 = mySucc.myInt $ n - 1

--to test a number, apply it to (+1) and 0
showInt f = f (+1) 0

--Define the successor function
--S = (\nab.a(nab))
--mySucc :: ((a->a)->a->a) -> (a->a)->a->a
--mySucc :: ((t1 -> t2) -> t3 -> t1) -> (t1 -> t2) -> t3 -> t2
mySucc = (\n a b -> a (n a b))

--Addition: 2 + 3 is simply 2S3 by defenition
--Note: the type signature is deduced by haskell
--myPlus :: ((((t1 -> t2) -> t3 -> t1) -> (t1 -> t2) -> t3 -> t2) -> t4 -> t5) -> t4 -> t5
--myPlus :: ((((a -> a) -> a -> a) -> (a -> a) -> a -> a) -> a -> a) -> a -> a
myPlus = (\a b -> a mySucc b)
--showInt (myPlus (myInt 2) (myInt 3))


--Multiplication
--myTimes :: (t1 -> t2) -> (t3 -> t1) -> t3 -> t2
--myTimes :: (a -> a) -> (a -> a) -> a -> a
myTimes = (\x y a -> x (y a))
--showInt (myTimes (myInt 4) (myInt 5))


--Boolean values
--myTrue :: a->a->a
myTrue = (\x y -> x)
--myFalse :: (a->a->a)
myFalse = (\x y -> y)

--Logical operations
--myAnd :: (t1->(p1->p2->p2)->t2) -> t1 -> t2
--myAnd :: (a->(a->a->a)->a) -> a -> a
myAnd = (\x y -> x y myFalse)
--myOr :: ((a -> a -> a) -> a -> a) -> a -> a
myOr = (\x y -> x myTrue y)
--myNot :: ((a -> a -> a) -> (a -> a -> a) -> t) -> t
myNot = (\x -> x myFalse myTrue)

--Show Boolean value
showBool b = b 'T' 'F'
--b = myAnd (myOr myTrue myFalse) (myOr (myAnd myTrue myFalse) (myOr myFalse myFalse))
--showBool b

-- A Conditional test: check if given number is 0
myZero = (\x -> x myFalse myNot myFalse)
--showBool.myZero $ myInt 0

-- Error: myZero cannot take (myInt 0) as input (type error)















