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

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int M = grid.size();
        if(!M) return 0;
        int N = grid[0].size();
        if(!N) return 0;
        vector<vector<int>> Up(M,vector<int>(N)),
                            Down(M,vector<int>(N)),
                            Left(M,vector<int>(N)),
                            Right(M,vector<int>(N));
        //Up
        for(int j = 0 ; j < N ; ++j){
            Up[0][j] = grid[0][j] == 'E';
            Down[M - 1][j] = grid[M - 1][j] == 'E';
        }
        for(int i = 0 ; i < M ; ++i){
            Left[i][0] = grid[i][0] == 'E';
            Right[i][N - 1] = grid[i][N - 1] == 'E';
        }
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(i)
                    Up[i][j] = grid[i][j] == 'W' ? 0 :
                               Up[i - 1][j] + (grid[i][j] == 'E');
                if(j)
                    Left[i][j] = grid[i][j] == 'W' ? 0 :
                                 Left[i][j - 1] + (grid[i][j] == 'E');
            }
        }
        
        int ANS = 0;
        for(int i = M - 1 ; i >= 0 ; --i){
            for(int j = N - 1 ; j >= 0 ; --j){
                if(i + 1 < M)
                    Down[i][j] = grid[i][j] == 'W' ? 0 :
                                 Down[i + 1][j] + (grid[i][j] == 'E');
                if(j + 1 < N)
                    Right[i][j] = grid[i][j] == 'W' ? 0 :
                                  Right[i][j + 1] + (grid[i][j] == 'E');
                if(grid[i][j] == '0'){
                    int D = Up[i][j] + Down[i][j] + Left[i][j] + Right[i][j];
                    if(D > ANS)
                        ANS = D;
                }
            }
        }
        return ANS;
    }
    void Test(){
        vector<vector<char>> grid = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
        //grid = vector<vector<char>>({{'E','E','E'}});
        printf("%d\n",maxKilledEnemies(grid));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
