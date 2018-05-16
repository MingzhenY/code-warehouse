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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(!M) return false;
        int N = matrix[0].size();
        if(!N) return false;
        int L = 0 , R = M * N;//[L,R) find last <= target
        while(L + 1 < R){
            int M = (L + R) >> 1;
            if(getV(matrix,N,M) <= target) L = M;
            else R = M;
        }
        return getV(matrix,N,L) == target;
    }
    int getV(vector<vector<int>>& matrix,int N,int I){
        return matrix[I / N][I % N];
    }
    void Test(){
        int A[3][4]=
        {
            { 1,  3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };
        vector<vector<int>> matrix;
        for(int i = 0 ; i < 3 ; ++i){
            matrix.push_back(vector<int>(A[i],A[i]+sizeof(A[i])/sizeof(A[i][0])));
        }
        cout<<searchMatrix(matrix,17)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
