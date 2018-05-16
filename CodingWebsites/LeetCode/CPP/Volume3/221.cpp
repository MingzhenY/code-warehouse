#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = matrix.size();
        if(!M) return 0;
        int N = matrix[0].size();
        if(!N) return 0;
        int L = 0;
        vector<vector<int>> C(M+1,vector<int>(N+1,0));
        for(int i = 1 ; i <= M ; ++i){
            for(int j = 1 ; j <= N ; ++j){
                C[i][j] = (matrix[i-1][j-1] - '0') + C[i-1][j] + C[i][j-1] - C[i-1][j-1];
                for(int k = 1 ; k <= i && k <= j; ++k){
                    int D = C[i][j] - C[i-k][j] - C[i][j - k] + C[i-k][j-k];
                    if(D != k * k) break;
                    if(D > L) L = D;
                }
            }
        }
        return L;
    }
    void Test(){
        vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };
        cout<<maximalSquare(matrix)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
