#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;


class Solution {
    struct P{
        int x,y;
        P(){}
        P(int x,int y):x(x),y(y){}
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        int ANS = 0;
        int M = grid.size();
        if(!M) return 0;
        int N = grid[0].size();
        if(!N) return 0;
        
        const int dx[] = {-1,0,1,0};
        const int dy[] = {0,1,0,-1};
        
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(grid[i][j] == '1'){
                    //Found new land, explore
                    ANS++;
                    queue<P> Q;
                    Q.push(P(i,j));
                    grid[i][j] = 'X';
                    while(!Q.empty()){
                        P t = Q.front();Q.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int nx = t.x + dx[k], ny = t.y + dy[k];
                            if(nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == '1'){
                                Q.push(P(nx,ny));
                                grid[nx][ny] = 'X';
                            }
                        }
                    }
                }
            }
        }
        //Change Back the 1s
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < N ; j++){
                if(grid[i][j] == 'X'){
                    grid[i][j] = '1';
                }
            }
        }
        return ANS;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
