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
    void gameOfLife(vector<vector<int>>& board) {
        int M = board.size();
        if(!M) return;
        int N = board[0].size();
        if(!N) return;
        //2 live neighbor, don't change
        //3 live neighbor, x -> live
        //other numbers  , x -> dead
        //how to implement this in place?
        //Since each state is only 1 bit and we have 32 bit in int
        //So Store the sum in bit 1-3 (max count is 8, but all we need is 0,1,2,3,4)
        //_..._cccx  where ccc is the count of it's live neighbours and x is it's current state
        int dx[] = {-1,-1,-1,0,1,1,1,0};
        int dy[] = {-1,0,1,1,1,0,-1,-1};
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(~ board[i][j] & 1) continue;
                for(int k = 0 ; k < 8 ; ++k){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && nx < M && ny >= 0 && ny < N){
                        int C = board[nx][ny] >> 1;
                        int X = board[nx][ny] & 1;
                        board[nx][ny] = ((C + 1) << 1) | X;
                    }
                }
            }
        }
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                int C = board[i][j] >> 1;
                int X = board[i][j] & 1;
                board[i][j] = C == 3 || (C == 2 && X);
            }
        }
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
