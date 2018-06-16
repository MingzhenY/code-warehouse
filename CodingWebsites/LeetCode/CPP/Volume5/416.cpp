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
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int Sum = 0;
        for(int i = 0 ; i < N ; ++i)
            Sum += nums[i];
        if(Sum % 2 == 1)
            return false;
        int M = Sum / 2;
        vector<vector<bool> > DP(N + 1, vector<bool>(M + 1, false));
        DP[0][0] = true;
        for(int i = 0 ; i < N ; ++i){
            Sum += nums[i];
            for(int j = 0 ; j <= M ; ++j)
                DP[i+1][j] = DP[i][j];
            for(int j = nums[i]; j <= M ; ++j)
                DP[i+1][j] = DP[i+1][j] || DP[i][j - nums[i]];
        }
        
        return DP[N][M];
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
