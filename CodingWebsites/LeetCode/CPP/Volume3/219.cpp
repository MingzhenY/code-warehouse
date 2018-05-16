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
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> S;
        int L = 0 , R = 0 , N = nums.size();//[L,R)
        while(R < N){
            //printf("(%d,%d):",L,R);
            //for(auto x:S) printf("%d ",x);
            //printf("\n");
            if(R - L <= k){
                if(S.count(nums[R])) return true;
                S.insert(nums[R++]);
                continue;
            }
            S.erase(nums[L++]);
            if(S.count(nums[R])) return true;
            S.insert(nums[R++]);
        }
        return false;
    }
    void Test(){
        vector<int> nums = {1,2,3,4,1,5,6,7};
        cout<<containsNearbyDuplicate(nums,4)<<endl;
        cout<<containsNearbyDuplicate(nums,3)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
