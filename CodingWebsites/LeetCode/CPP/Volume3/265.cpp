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
    int minCostII(vector<vector<int>>& costs) {
        int N = costs.size();
        if(!N) return 0;
        int K = costs[0].size();
        if(K == 1) return N == 1 ? costs[0][0] : 0;
        vector<vector<int>> D(2,vector<int>(K,0));
        for(int i = 0 ; i < N ; ++i){
            int I = i & 1, _I = ~ i & 1;
            vector<int> L(K,INT_MAX),R(K,INT_MAX);
            for(int j = 1 ; j < K ; ++j)
                L[j] = min(L[j-1],D[_I][j-1]);
            for(int j = K - 2 ; j >= 0 ; --j)
                R[j] = min(R[j+1],D[_I][j+1]);
            for(int j = 0 ; j < K ; ++j){
                D[I][j] = min(L[j],R[j]) + costs[i][j];
                //printf("%d%c",D[I][j],j+1==K?'\n':' ');
            }
        }
        int MinCost = INT_MAX, n = ~ N & 1;
        for(int j = 0 ; j < K ; ++j)
            MinCost = min(MinCost,D[n][j]);
        return MinCost;
    }
    void Test(){
        vector<vector<int>> costs = {
            {20,19,11,13,12,16,16,17,15,9,5,18},
            { 3, 8,15,17,19, 8,18, 3,11,6,7,12},
            {15, 4,11, 1,18, 2,10, 9, 3,6,4,15}};
        cout<<minCostII(costs)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
