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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int N = nums.size();
        for(int i = 0 ; i < N ; ++i){
            if(nums[i] == i + 1) continue;
            int t = nums[i];
            nums[i] = -1;
            while(t != -1 && nums[t - 1] != t){
                //put t into position t - 1
                int newt = nums[t - 1];
                nums[t - 1] = t;
                t = newt;
            }
        }
        
        for(int i = 0 ; i < N ; ++i){
            if(nums[i] == -1)
                ret.push_back(i + 1);
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> ret = findDisappearedNumbers(nums);
        for(auto x : ret){
            cout<<x<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
