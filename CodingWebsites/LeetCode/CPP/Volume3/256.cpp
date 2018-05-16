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
    int minCost(vector<vector<int>>& costs) {
        int D[2][3] = {0,0,0,0,0,0};
        int n = costs.size();
        if(!n) return 0;
        for(int i = 0 ; i < n ; ++i){
            int I = i & 1, _I = ~ i & 1;
            D[I][0] = costs[i][0] + min(D[_I][1],D[_I][2]);
            D[I][1] = costs[i][1] + min(D[_I][0],D[_I][2]);
            D[I][2] = costs[i][2] + min(D[_I][0],D[_I][1]);
        }
        int I = ~n&1;
        return min(D[I][0],min(D[I][1],D[I][2]));
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
