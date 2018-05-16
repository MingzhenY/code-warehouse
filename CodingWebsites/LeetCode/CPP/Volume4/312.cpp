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
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> DP(N,vector<int>(N,-1));
        for(int j = N - 1 ; j >= 0 ; --j){
            for(int i = j ; i < N ; ++i){
                //DP[i][j] <- interval [i,j]
                for(int k = i ; k = j ; ++k){
                    int D = 
                }
            }
        }
    }
    int getElem(vector<int>& nums,int id){
        return id >= 0 && id <= nums.size() ? nums[id] : 1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
