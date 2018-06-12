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
    int F(int x,int a,int b,int c){
        return a * x * x + b * x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if(a < 0){
            vector<int> ret = sortTransformedArray(nums,-a,-b,-c);
            reverse(ret.begin(),ret.end());
            for(int i = 0 ; i < ret.size() ; ++i)
                ret[i] = - ret[i];
            return ret;
        }
        int L = 0, R = nums.size() - 1;
        vector<int> ret;
        while(L <= R){
            int VL = F(nums[L],a,b,c);
            int VR = F(nums[R],a,b,c);
            if(VL > VR){
                ret.push_back(VL);
                ++L;
            }
            else{
                ret.push_back(VR);
                --R;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    void Test(){
        vector<int> nums = {-4,-2,2,4};
        vector<int> ret = sortTransformedArray(nums,-1,3,5);
        for(auto x:ret){
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
