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
    int minTotalDistance(vector<vector<int>>& grid) {
        int M = grid.size();
        if(!M) return 0;
        int N = grid[0].size();
        if(!N) return 0;
        vector<int> Row(M,0),Col(N,0);
        int A = 0, D = 0, X = 0, Y = 0;
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(grid[i][j]){
                    ++Row[i];
                    ++Col[j];
                    ++A;
                    D += i + j;
                }
            }
        }
        for(int i = 1 ; i < M ; ++i) Row[i] += Row[i - 1];
        for(int i = 1 ; i < N ; ++i) Col[i] += Col[i - 1];
        while(X + 1 < M && Row[X] * 2 < A){
            D += 2 * Row[X] - A;
            ++X;
        }
        while(Y + 1 < N && Col[Y] * 2 < A){
            D += 2 * Col[Y] - A;
            ++Y;
        }
        return D;
    }
    void Test(){
        vector<vector<int>> grid = {
            {1,0,0,0,1},
            {0,0,0,0,0},
            {0,0,1,0,0}
        };
        cout<<minTotalDistance(grid)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
