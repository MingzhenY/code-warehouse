# GameOfLife
Try to write Game of Life.  
This is the first c++ program that I learned.  
So I think it would be fun to write it in Haskell.  

## Rules:
let n be the number of neighbours a cell have (max 8)  
    s be the current state of the cell  
then  
    alive :: (Int,Int)->Int  
    alive (s,2) = s  
    alive (_,3) = 1  
    alive _ = 0  
## Notes:
### sleep function
Trying to find a sleep function.  
Documents recommends Control.Concurrent.threadDelay,  
but threadDelay doesn't has any effect.  
So each time user type "Enter", the game moves to its next state.  
### stdout
Showing a matrix on commandline does not look good  
Maybe I will use a GUI to implement this in the future.  