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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int N = nums.size();
        for(int i = 0 ; i < N ; ++i){
            if(nums[i] == i + 1 || nums[i] == -1) continue;
            int val = nums[i];
            nums[i] = -1;
            while(val != -1){
                int new_val = nums[val - 1];
                if(new_val == val){
                    ret.push_back(val);
                    break;
                }
                else{
                    nums[val - 1] = val;
                    val = new_val;
                }
            }
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> ans = findDuplicates(nums);
        for(auto x:ans){
            printf("%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
