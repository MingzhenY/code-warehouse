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
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        if(!M) return 0;
        int N = grid[0].size();
        vector<vector<int>> D(M + 1 , vector<int>(N + 1, INT_MAX));
        for(int i = 1 ; i <= M ; ++i){
            for(int j = 1 ; j <= N ; ++j){
                D[i][j] = grid[i - 1][j - 1];
                int Past = min(D[i - 1][j],D[i][j - 1]);
                D[i][j] += Past != INT_MAX ? Past : 0;
                printf("%d ",D[i][j]);
            }
            printf("\n");
        }
        return D[M][N];
    }
    void Test(){
        vector<vector<int>> grid(3,vector<int>(4,0));
        int A[3][4] = {
            {1,2,3,4},
            {7,4,5,2},
            {8,5,2,4}
        };
        for(int i = 0 ; i < 3 ; ++i){
            for(int j = 0 ; j < 4 ; ++j){
                grid[i][j] = A[i][j];
            }
        }
        cout<<minPathSum(grid)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
