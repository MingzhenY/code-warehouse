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
/*
  reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]...
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1 ; i < n ; ++i){
            if(((i & 1) && nums[i] < nums[i-1]) || ( (~i&1) && nums[i] > nums[i-1] ))
                swap(nums[i-1],nums[i]);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
