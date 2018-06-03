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
    #define LL long long
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end(),std::greater<int>());
        int N = coins.size();
        int M = amount;
        //DP[x][i] -> the min number of coins to get i using coins[0..x]
        vector<vector<int>> DP(N + 1,vector<int>(M + 1,-1));
        DP[0][0] = 0;
        for(int i = 0 ; i < N ; ++i){
            //for(int j = 0 ; j <= M ; ++j)
            //    DP[i + 1][j] = DP[i][j];
            for(int j = 0 ; j <= M ; ++j){
                if(DP[i][j] == -1) continue;
                for(LL k = 0, kv = j ; kv <= M ; k++, kv += coins[i]){
                    int newCount = DP[i][j] + k;
                    if(DP[i + 1][kv] == -1 || newCount < DP[i + 1][kv])
                        DP[i + 1][kv] = newCount;
                }
                //printf("DP[%d][%d]=%d\n",i,j,DP[i][j]);
            }
        }
        return DP[N][M];
    }
    void Test(){
        vector<int> coins = {1,2,5};
        int X = coinChange(coins,11);
        printf("%d\n",X);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
