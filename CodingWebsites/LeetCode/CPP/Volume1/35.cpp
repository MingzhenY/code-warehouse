#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        if(target > nums[N - 1]) return N;
        
        int L = 0 , R = N - 1 , M;//[L,R] first >= target
        while(L ^ R){
            M = (L + R) >> 1;
            if(nums[M] >= target) R = M;
            else L = M + 1;
        }
        return L;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
