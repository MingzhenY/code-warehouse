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
    vector<pair<int,int>> v;
public:
    Solution(vector<int> nums) {
        for(int i = 0 ; i < nums.size() ; ++i){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        for(int i = 0 ; i < v.size() ; ++i){
            printf("(%d,%d)\n",v[i].first,v[i].second);
        }
    }
    
    int pick(int target) {
        pair<int,int> VL = make_pair(target,-1),VR = make_pair(target,v.size());
        int IL = lower_bound(v.begin(),v.end(),VL) - v.begin();
        int IR = upper_bound(v.begin(),v.end(),VR) - v.begin();
        printf("IL = %d, IR = %d\n",IL,IR);
        int rn = rand() % (IR - IL) + IL;
        return v[rn].second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(){
    vector<int> nums = {1,2,3,3,3};
    Solution S(nums);
    printf("%d\n",S.pick(3));
	return 0;
}
