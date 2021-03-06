import Test.Hspec
import Lib
import System.Random

test_makeRandomGame :: StdGen -> (Int,Int) -> [Bool]
test_makeRandomGame gen (x,y) =
    let gb = gameBoard $ makeRandomGame gen (x,y)
        t1 = length gb == x + 2
        t2 = and $ map ((== y + 2).length) gb
    in [t1,t2]




main :: IO ()
main = hspec $ do
    describe "makeRandomBoard x y" $ do
      it "Board (x,y) Should be (x+2)*(y+2) grid" $ do
        gen <- newStdGen
        (and $ test_makeRandomGame gen (2,2)) `shouldBe` True
        (and $ test_makeRandomGame gen (3,4)) `shouldBe` True
        (and $ test_makeRandomGame gen (1,7)) `shouldBe` True
        (and $ test_makeRandomGame gen (3,10)) `shouldBe` True

