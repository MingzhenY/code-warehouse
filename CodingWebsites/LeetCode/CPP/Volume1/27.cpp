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
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        int L = 0 , R = N;
        while(R >= 1 && nums[R - 1] == val) --R;
        while(L < R){
            if(nums[L] == val){
                swap(nums[L],nums[--R]);
                while(R >= 1 && nums[R - 1] == val) --R;
            }
            ++L;
        }
        nums.resize(R);
        return R;
    }
    void Test(){
        int S[] = {1,4,3,2,5,4,3,4,4};
        vector<int> A(S,S + sizeof(S) / sizeof(S[0]));
        cout<<removeElement(A,4)<<endl;
        for(auto x:A){
            printf("->%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
