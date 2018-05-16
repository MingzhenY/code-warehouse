#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int M = matrix.size();
        if(!M) return 0;
        int N = matrix[0].size();
        if(!N) return 0;
        vector<int> H(N + 1,0);
        int MaxArea = 0;
        for(int i = 0 ; i < M ; ++i){
            matrix[i].resize(N + 1);
            matrix[i][N] = 0;
            stack<int> S;
            for(int j = 0 ; j <= N ; ++j){
                H[j] =
                matrix[i][j] == '1' ? H[j] + 1
                             : 0;
                while(!S.empty() && H[j] < H[S.top()]){
                    int Cnt = S.top();
                    S.pop();
                    int L = S.empty()? -1 : S.top();
                    int C = H[Cnt] * (j - L - 1);
                    MaxArea = max(MaxArea,C);
                }
                if(S.empty() || H[j] >= H[S.top()]){
                    S.push(j);
                }
            }
        }
        return MaxArea;
    }
    void Test(){
        int A[4][5] =
        {
            {1,0,1,0,0},
            {1,0,1,1,1},
            {1,1,1,1,1},
            {1,0,0,1,0}
        };
        vector<vector<char>> matrix(4,vector<char>(5));
        for(int i = 0 ; i < 4 ; ++i){
            for(int j = 0 ; j < 5 ; ++j){
                matrix[i][j] = '0' + A[i][j];
            }
        }
        cout<<maximalRectangle(matrix)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
