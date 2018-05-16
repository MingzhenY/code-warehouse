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
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0 ; i < N ; ++i){
            if(nums[i] >= 1 && nums[i] <= N && nums[i] != nums[nums[i] - 1]){
                swap(nums[i],nums[nums[i] - 1]);
                --i;
            }
        }
        for(int i = 0 ; i < N ; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        return N + 1;
    }
    void Test(){
        int A[] = {1,1};
        vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
        cout<<firstMissingPositive(nums)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
