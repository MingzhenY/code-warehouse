#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x = 0 , y = 0 ;
        int dx = 0 , dy = 1;
        vector<vector<int>> ANS(n,vector<int>(n,0));
        int N = n * n;
        for(int i = 1 ; i <= N ; ++i){
            ANS[x][y] = i;
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || ANS[nx][ny]){
                //Change Direction
                dx = dx ^ dy;
                dy = dx ^ dy;
                dx = dx ^ dy;
                dy = - dy;
                //Update nx,ny
                nx = x + dx;
                ny = y + dy;
            }
            x = nx;
            y = ny;
        }
        return ANS;
    }
    void Test(){
        vector<vector<int>> ANS = generateMatrix(4);
        for(auto line: ANS){
            for(auto x:line){
                printf("%d ",x);
            }
            printf("\n");
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
