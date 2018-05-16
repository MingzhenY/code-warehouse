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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(!M) return vector<int>();
        int N = matrix[0].size();
        vector<vector<bool>>Vis(M,vector<bool>(N,false));
        int x = 0 , y = 0 , Left = M * N;
        int dx = 0 , dy = 1;//->
        vector<int> ANS;
        while(Left-- > 0){
            //Mark visited
            Vis[x][y] = true;
            ANS.push_back(matrix[x][y]);
            
            //Find Next Cell
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || Vis[nx][ny]){
                //Change direction
                dx = dx ^ dy;
                dy = dx ^ dy;
                dx = dx ^ dy;
                dy = - dy;
                //Update nx,ny
                nx = x + dx;
                ny = y + dy;
            }
            //Move
            x = nx;
            y = ny;
        }
        return ANS;
    }
    void Test(){
        int A[3][4] = {
            {1,2,3,7},
            {4,5,6,2},
            {7,8,9,11}
        };
        vector<vector<int>> V;
        for(int i = 0 ; i < 3 ; ++i){
            V.push_back(vector<int>(A[i],A[i]+sizeof(A[i])/sizeof(A[i][0])));
        }
        vector<int> ANS = spiralOrder(V);
        for(auto x:ANS){
            printf("%d,",x);
        }
        printf("\n");
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
