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

class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int M = matrix.size();
        if(!M) return;
        int N = matrix[0].size();
        if(!N) return;
        sum = vector<vector<int>> (M+1, vector<int>(N+1,0));
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                sum[i+1][j+1] = matrix[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
