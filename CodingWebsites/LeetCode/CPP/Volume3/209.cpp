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
    int minSubArrayLen(int s, vector<int>& nums) {
        int N = nums.size();
        int L = 0 , R = 0 ;//[L,R)
        int MinLen = N + 1;
        long long Sum = 0;
        while(L < N){
            if(Sum < s){
                if(R < N){
                    Sum += nums[R++];
                }
                else break;
            }
            else{
                MinLen = min(MinLen,R - L);
                Sum -= nums[L++];
            }
        }
        return MinLen != N + 1 ? MinLen : 0;
    }
    void Test(){
        vector<int> nums = {2,3,1,2,4,3};
        cout<<minSubArrayLen(7,nums)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
