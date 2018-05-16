#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define assert(func,cond) if(cond) ; else { cout<<"("<<#cond<<") fails in "<<#func<<endl;}

class Solution {
private:
    #define u16 unsigned short
    int countBit(u16 x){
        x = (x & 0x5555) + ((x & 0xaaaa)>>1);
        x = (x & 0x3333) + ((x & 0xcccc)>>2);
        x = (x & 0x0f0f) + ((x & 0xf0f0)>>4);
        x = (x & 0x00ff) + ((x & 0xff00)>>8);
        return x;
    }
public:

    void solveSudoku(vector<vector<char>>& board) {
        SolveOne(board);
        
    }
    void SolveOne(vector<vector<char>>& board){
        u16 B[9][9];//Use bits to indicate which number can be used
        bool Vis[9][9];
        //Step One: Set B[i][j] to 111111111
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                B[i][j] = (1 << 9) - 1;
                Vis[i][j] = false;
            }
        }
        //Step Two: Build Queue
        queue<int> One;//Store Cells that have only one choise
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j] != '.'){
                    One.push((i << 4) | j);
                    B[i][j] = 1 << (board[i][j] - '1');
                }
            }
        }
        
        //Step Three: Eliminate Choices
        
        while(!One.empty()){
            int y = One.front(); One.pop();
            int x = y >> 4; y &= 15;
            int Mask = B[x][y];
            Vis[x][y] = true;
            assert(SolveOne,countBit(Mask)==1);
            for(int i = 0 ; i < 9 ; ++i){
                int X,Y;
                
                X = x , Y = i ;
                B[X][Y] &= ~Mask;
                if(!Vis[X][Y] && countBit(B[X][Y]) == 1){
                    One.push((X << 4) | Y);
                }
                
                X = i , Y = y ;
                B[X][Y] &= ~Mask;
                if(!Vis[X][Y] && countBit(B[X][Y]) == 1){
                    One.push((X << 4) | Y);
                }
                
                X = x / 3 * 3 + i / 3 , Y = y / 3 * 3 + i % 3 ;
                B[X][Y] &= ~Mask;
                if(!Vis[X][Y] && countBit(B[X][Y]) == 1){
                    One.push((X << 4) | Y);
                }
            }
            B[x][y] = Mask;
        }
    }
    
    void Test(){
        char board[9][10] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"};
        
        vector<vector<char>> B(9);
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                B[i].push_back(board[i][j]);
            }
        }
        
        for(auto line : B){
            for(auto ch : line){
                cout<<ch;
            }
            cout<<endl;
        }
        cout<<endl;
        
        solveSudoku(B);
        
        for(auto line : B){
            for(auto ch : line){
                cout<<ch;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
