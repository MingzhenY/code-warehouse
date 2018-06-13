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
    int getMoneyAmount(int n) {
        vector<vector<int>> DP(n+1,vector<int>(n+1));
        for(int i = n ; i >= 0 ; --i){
            for(int j = i ; j <= n ; ++j){
                //[i,j]
                if(i == j){
                    DP[i][j] = 0;
                    continue;
                }
                if(i + 1 == j){
                    DP[i][j] = i;
                    continue;
                }
                int Cost = -1;
                for(int k = i + 1 ; k < j ; ++k){
                    //[i,k-1] - [k+1,j]
                    int Costk = k + max(DP[i][k-1],DP[k+1][j]);
                    if(-1 == Cost || Costk < Cost){
                        Cost = Costk;
                    }
                }
                DP[i][j] = Cost;
            }
        }
        return DP[1][n];
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
