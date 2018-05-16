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
    int removeDuplicates(vector<int>& nums) {
        bool Valid = false;
        int Value;
        int Count;
        int N = nums.size();
        int I = 0;
        for(int i = 0 ; i < N ; ++i){
            if(!Valid){
                Value = nums[i];
                Count = 1;
                Valid = true;
            }
            else ++Count;
            if(i + 1 == N || nums[i + 1] != nums[i]){
                //Record Answer
                if(Count > 2) Count = 2;
                for(int j = 0 ; j < Count ; ++j) nums[I++] = nums[i];
                //Reset
                Valid = false;
            }
            
        }
        nums.resize(I);
        
        return I;
    }
    void Test(){
        int A[] = {1,1,1,2,2,3,3,3,4};
        vector<int> nums(A,A+sizeof(A)/sizeof(A[0]));
        cout<<removeDuplicates(nums)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
