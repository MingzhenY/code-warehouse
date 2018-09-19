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
    int islandPerimeter(vector<vector<int>>& grid) {
        int M = grid.size();
        if(!M) return 0;
        int N = grid[0].size();
        if(!N) return 0;
        int ANS = 0;
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(grid[i][j] == 0) continue;
                ANS += i == 0 || grid[i-1][j] == 0;
                ANS += i == M - 1 || grid[i + 1][j] == 0;
                ANS += j == 0 || grid[i][j-1] == 0;
                ANS += j == N - 1 || grid[i][j+1] == 0;
            }
        }
        return ANS;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
