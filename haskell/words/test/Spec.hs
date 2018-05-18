import Test.Hspec
import Lib
import Data

gwc = gridWithCoords grid 

testFindWord word =
    let (Just result) = findWord gwc word
        string = map cell2char result
    in string `shouldBe` word

main :: IO ()
main = hspec $ do
    describe "formatGrid" $ do
      it "Should concatenate every line with a newline" $ do
        formatGrid (gridWithCoords ["abc","def","ghi"]) `shouldBe` "abc\ndef\nghi\n"


    describe "findWord" $ do
        it "Should find words that exist on Grid" $ do
            testFindWord "HASKELL"
            testFindWord "PERL"
        it "Should not find words that do not exist in Grid" $ do
            findWord gwc "HAMSTER" `shouldBe` Nothing

    describe "FindWords" $ do
      it "Shoud find all words in word-list" $ do
        let found = findWords gwc languages
            asString = map (map cell2char) found
        asString `shouldBe` languages
      it "Should not find words in word-list" $ do
        let found = findWords gwc ["ENGLISH","CHINESE","FRENCH"]
        found `shouldBe` []

