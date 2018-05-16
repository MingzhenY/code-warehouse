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
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int N = nums.size(), ANS = 0;
        for(int i = 0 ; i < N ; ++i){
            //search j,k that nums[j] + nums[k] < target - nums[i]
            int L = i + 1, R = N - 1, T = target - nums[i];//[L,R]
            while(L < R){
                if(nums[L] + nums[R] < T){
                    //[L]+[R] < T => [L]+[L+1..R] < T
                    ANS += R - L;
                    ++L;
                }
                else{
                    //[L]+[R] >= T
                    --R;
                }
            }
        }
        return ANS;
    }
    void Test(){
        vector<int> nums = {1,1,-2};
        cout<<threeSumSmaller(nums,1)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
