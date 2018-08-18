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
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        if(!N) return false;
        
        set<int> S;
        vector<int> Min(N);
        Min[0] = nums[0];
        for(int i = 1 ; i < N ; ++i){
            Min[i] = min(Min[i-1],nums[i]);
        }
        
        for(int i = N - 1 ; i >= 0 ; --i){
            S.insert(nums[i]);
            auto p = S.find(nums[i]);
            if(p != S.begin()){
                if(*--p > Min[i]){
                    return true;
                }
            }
        }
        return false;
    }
    void Test(){
        vector<int> nums = {1,2,3,4};
        cout<<find132pattern(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
