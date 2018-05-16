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
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;
        //n is at least 3 at this point
        int L = 0 , R = n - 1;
        //nums[L] < nums[L + 1] is always true
        //nums[R] > nums[R - 1] is always true
        while(L + 2 != R){
            int M = (L + R) >> 1;
            if(nums[M] > nums[M - 1] && nums[M] > nums[M + 1]){
                //M is a peak just return
                return M;
            }
            //If M is not peak, one of the following is true
            //1. nums[M] < nums[M+1]
            //2. nums[M] < nums[M-1]
            if(nums[M] < nums[M + 1]){
                L = M;
            }else if(nums[M - 1] > nums[M]){
                R = M;
            }else{
                printf("ERROR");
                break;
            }
        }
        return (L + R) >> 1;
    }
    void Test(){
        int A[] = {1,31,5,1,0,2,1};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<findPeakElement(V)<<endl;
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
