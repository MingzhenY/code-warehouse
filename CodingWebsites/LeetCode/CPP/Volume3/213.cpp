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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n == 1) return nums[0];
        int S1, S2;
        int F0, F1;
        //First Case: the first house is robbed
        F0 = nums[0];
        F1 = nums[0];
        for(int i = 2 ; i < n - 1; i++){
            int F = max(nums[i] + F0, F1);
            F0 = F1;
            F1 = F;
        }
        S1 = F1;
        
        //Second Case: the first house is not robbed
        F0 = 0;
        F1 = nums[1];
        for(int i = 2 ; i < n ; i++){
            int F = max(nums[i] + F0, F1);
            F0 = F1;
            F1 = F;
        }
        S2 = F1;
        
        return max(S1,S2);
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
