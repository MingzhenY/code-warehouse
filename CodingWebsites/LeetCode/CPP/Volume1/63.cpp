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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        if(!M) return 0;
        int N = obstacleGrid[0].size();
        //N * M Grid
        vector<vector<int>> D(M,vector<int>(N,0));
        D[M - 1][N - 1] = !obstacleGrid[M - 1][N - 1];
        for(int i = M - 1 ; i >= 0 ; --i){
            for(int j = N - 1 ; j >= 0 ; --j){
                if(obstacleGrid[i][j]) continue;
                D[i][j] += i + 1 < M ? D[i + 1][j] : 0;
                D[i][j] += j + 1 < N ? D[i][j + 1] : 0;
            }
        }
        return D[0][0];
    }
    void Test(){
        vector<vector<int>> OG(3,vector<int>(4,0));
        OG[1][1] = 1;
        cout<<uniquePathsWithObstacles(OG)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
