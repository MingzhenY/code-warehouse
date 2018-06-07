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
    bool increasingTriplet(vector<int>& nums) {
        int E1, E2;
        bool hasE1, hasE2;
        hasE1 = hasE2 = false;
        for(auto x : nums){
            //1. test for E3
            if(hasE2 && E2 < x)
                return true;
            //2. test for E2
            if(hasE1 && E1 < x){
                int cntE2 = x;
                if(!hasE2 || cntE2 < E2){
                    E2 = cntE2;
                    hasE2 = true;
                }
            }
            //3. test for E1
            int cntE1 = x;
            if(!hasE1 || cntE1 < E1){
                E1 = cntE1;
                hasE1 = true;
            }
        }
        return false;
    }
    void Test(){
        vector<int> nums = {1,0,0,0,10,0,0,3};
        printf("%d\n",increasingTriplet(nums));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
