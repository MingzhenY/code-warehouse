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

class Solution1 {
    /*
     O(n logn) solution: devide and conquer
     */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        if(n == 1) return {1};
        vector<int> ret = vector<int>(n,1);
        F(nums,ret,0,nums.size()-1);
        return ret;
    }
    int F(vector<int> &nums, vector<int> &ret, int L,int R){
        if(L == R){
            ret[L] = 1;
            return nums[L];
        }
        int M = (L + R) >> 1;
        //[L,M] + [M+1,R]
        int PL = F(nums,ret,L,M);
        int PR = F(nums,ret,M+1,R);
        for(int i = L ; i <= M ; ++i) ret[i] *= PR;
        for(int i = M + 1 ; i <= R ; ++i) ret[i] *= PL;
        return PL * PR;
    }
    void Test(){
        vector<int> nums = {1,2,3,4};
        vector<int> ret = productExceptSelf(nums);
        for(auto x:ret){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
class Solution {
    /*
     O(n)
     */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(!n) return {};
        vector<int> ret = vector<int>(n,1);
        ret[0] = nums[0];
        for(int i = 1 ; i < n ; ++i) ret[i] = ret[i - 1] * nums[i];
        int p = 1;
        for(int i = n - 1 ; i >= 0 ; --i){
            ret[i] = i ? ret[i - 1] * p : p;
            p *= nums[i];
        }
        return ret;
    }
    void Test(){
        vector<int> nums = {1,2,3,4};
        vector<int> ret = productExceptSelf(nums);
        for(auto x:ret){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
