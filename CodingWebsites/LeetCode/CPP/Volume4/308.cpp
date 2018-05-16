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
    vector<vector<int>> sum,A;
    int M,N;
public:
    NumMatrix(vector<vector<int>> matrix) {
        M = matrix.size();
        if(!M) return;
        N = matrix[0].size();
        if(!N) return;
        sum = vector<vector<int>> (M+1,vector<int>(N+1,0));
        A = matrix;
        for(int i = 0 ; i < M ; ++i)
            for(int j = 0 ; j < N ; ++j)
                for(int x = i + 1 ; x <= M ; x += x & -x)
                    for(int y = j + 1 ; y <= N ; y += y & -y)
                        sum[x][y] += A[i][j];
    }
    
    void update(int row, int col, int val) {
        int diff = val - A[row][col];
        A[row][col] = val;
        for(int x = row + 1; x <= M ; x += x & -x)
            for(int y = col + 1 ; y <= N ; y += y & -y)
                sum[x][y] += diff;
        
    }
    int Sum(int row,int col){
        int ANS = 0;
        for(int x = row ; x ; x -= x & -x)
            for(int y = col ; y ; y -= y & -y)
                ANS += sum[x][y];
        return ANS;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return Sum(row2+1,col2+1) - Sum(row1,col2+1) - Sum(row2+1,col1) + Sum(row1,col1);
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
