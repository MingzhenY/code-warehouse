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
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        if(!N || target < nums[0] || target > nums[N - 1]) return vector<int>(2,-1);
        int LID = BinarySearch(nums,target - 1);
        int RID = BinarySearch(nums,target);
        if(LID == RID){
            return vector<int>(2,-1);
        }
        else{
            vector<int> ANS;
            ANS.push_back(LID + 1);
            ANS.push_back(RID);
            return ANS;
        }
        
    }
    int BinarySearch(vector<int> nums,int target){
        //Find largest I that nums[I] <= target
        if(target < nums[0]) return -1;
        int N = nums.size();
        int L = 0 , R = N;//[L,R)
        while(L + 1 < R){
            int M = (L + R) >> 1;
            if(nums[M] <= target) L = M;
            else R = M;
        }
        return L;
    }
    void Test(){
        int S[] = {1,5};
        vector<int> V(S,S+sizeof(S)/sizeof(S[0]));
        vector<int> ANS = searchRange(V,4);
        for(auto x : ANS){
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
