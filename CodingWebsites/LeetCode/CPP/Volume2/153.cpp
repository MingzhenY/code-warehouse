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
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] < nums[n - 1]) return nums[0];
        int L = 0 , R = n - 1;//[L,R]
        while(L < R){
            int M = (L + R) >> 1;
            if(nums[M] >= nums[0]) L = M + 1;
            else R = M;
        }
        return nums[L];
    }
    void Test(){
        int A[]={2,1};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<findMin(V)<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
