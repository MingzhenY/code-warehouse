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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(!A.size() || !B.size() || !B[0].size()) return {};
        int I = A.size(), J = B.size(), K = B[0].size();
        vector<vector<int>> V(I,vector<int>(K,0));
        for(int i = 0 ; i < I ; ++i){
            for(int j = 0 ; j < J ; ++j){
                for(int k = 0 ; k < K ; ++k){
                    V[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return V;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
