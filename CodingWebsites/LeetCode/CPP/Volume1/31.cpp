#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int I = N - 1;
        //Find I
        while(I > 0 && nums[I - 1] >= nums[I]) --I;
        //Switch nums[I - 1] with the right number
        if(I > 0){
            int L = I , R = N;//[L,R)
            while(L + 1 < R){
                int M = (L + R) >> 1;
                if(nums[M] > nums[I - 1]) L = M;
                else R = M;
            }
            
            swap(nums[I - 1],nums[L]);
        }
        //reverse nums[I,N)
        int n = N - I;
        for(int i = 0 ; i < n / 2 ; ++i){
            swap(nums[I + i],nums[N - i - 1]);
        }
    }
    void Test(){
        int A[] = {3,2,1};
        vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
        nextPermutation(nums);
        for(auto x:nums){
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
