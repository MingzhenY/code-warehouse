#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <map>
#include <set>
#include <stack>
using namespace std;

class SnakeGame {
    int W,H;
    list<pair<int,int>> Snake;
    int F,score;
    vector<pair<int, int>> Foods;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        Foods = food;
        W = width;
        H = height;
        Snake.push_front(make_pair(0,0));
        F = 0;
        score = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        //Step One: Move
        auto cnt = *Snake.begin();
        int X = cnt.first;
        int Y = cnt.second;
        switch(direction[0]){
            case 'U':
                X -= 1;
                break;
            case 'D':
                X += 1;
                break;
            case 'L':
                Y -= 1;
                break;
            case 'R':
                Y += 1;
                break;
        }
        //Step Two: Check if game over
        if(X < 0 || X >= H || Y < 0 || Y >= W){
            return -1;
        }
        
        
        pair<int,int> Head = make_pair(X,Y);
        //Step Three: Check if reach food
        if(F < Foods.size() && Head == Foods[F]){
            score++;
            F++;
        }
        else{
            Snake.pop_back();
        }
        for(auto x:Snake){
            if(x.first == X && x.second == Y)
                return -1;
        }
        Snake.push_front(Head);
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main(){
    SnakeGame S(3,3,{make_pair(2,0),make_pair(0,0),make_pair(0,2),make_pair(2,2)});
    string moves = "DDRUULDRRULD";
    for(auto ch : moves){
        string s(1,ch);
        printf("%d ",S.move(s));
    }
    printf("\n");
	return 0;
}
