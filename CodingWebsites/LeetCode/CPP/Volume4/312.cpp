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
        vector<vector<int>> DP(N+1,vector<int>(N+1,0));
        for(int i = N - 1 ; i >= 0 ; --i){
            for(int j = i + 1, L = 1 ; j <= N ; ++j, ++L){
                // [i,j) has length L
                int maxD = 0;
                for(int k = i ; k < j ; ++k){
                    // try burst k first
                    int DL, DM, DR, D;
                    DL = DM = DR = 0;
                    if(k > i) DL = DP[i][k];
                    if(k + 1 < j) DR = DP[k + 1][j];
                    DM = getElem(nums,i-1) * getElem(nums,k) * getElem(nums,j);
                    D = DL + DM + DR;
                    if(D > maxD)
                        maxD = D;
                }
                DP[i][j] = maxD;
            }
        }
        return DP[0][N];
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
