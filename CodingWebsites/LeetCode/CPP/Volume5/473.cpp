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
    bool makesquare(vector<int>& nums) {
        int N = nums.size();
        int Sum = 0;
        for(auto x : nums)
            Sum += x;
        int D = Sum / 4;
        if(Sum % 4 != 0 || D == 0)
            return false;
        return SplitSide(nums,0,N,D,0,0,0,0);
    }
    bool SplitSide(vector<int>& nums,int k,int N,int D,int Sum0,int Sum1,int Sum2,int Sum3){
        return k == N ? true:
               (Sum0 + nums[k] <= D && SplitSide(nums,k+1,N,D,Sum0+nums[k],Sum1,Sum2,Sum3)) ||
               (Sum1 + nums[k] <= D && SplitSide(nums,k+1,N,D,Sum0,Sum1+nums[k],Sum2,Sum3)) ||
               (Sum2 + nums[k] <= D && SplitSide(nums,k+1,N,D,Sum0,Sum1,Sum2+nums[k],Sum3)) ||
               (Sum3 + nums[k] <= D && SplitSide(nums,k+1,N,D,Sum0,Sum1,Sum2,Sum3+nums[k]));
    }
    void Test(){
        vector<int> V1={1,1,2,2,2};
        printf("makesquare=%d\n",makesquare(V1));
        
        vector<int> V2={3,3,3,3,4};
        printf("makesquare=%d\n",makesquare(V2));
    }
};

class Solution2 {
/*
TLE
*/
public:
    bool makesquare(vector<int>& nums) {
        int N = nums.size();
        int S = 0;
        for(auto x : nums)
            S += x;
        int D = S / 4;
        if(S % 4 != 0 || D == 0)
            return false;
        return SplitSide(nums,N,D,0);
    }
    bool SplitSide(vector<int>& nums,int N,int D,int Group){
        if(N == 0){
            return Group == 4;
        }
        //Find a subset that sums to D
        int B = 1 << N;
        for(int k = 0 ; k < B ; ++k){
            int Sum = 0;
            int nVec = N;
            int Mask = 0;
            for(int s = k, i=0;s;s>>=1,i++){
                if(s&1){
                    Sum += nums[i];
                    nVec --;
                }
            }
            
            if(Sum == D){
                vector<int> Vec(nVec);
                int pVec = 0;
                for(int s = k, i=0;s;s>>=1,i++){
                    if(~s&1){
                        Vec[pVec++] = nums[i];
                    }
                }
                if(SplitSide(Vec,nVec,D,Group+1))
                    return true;
            }
        }
        return false;
    }
    void Test(){
        vector<int> V1={1,1,2,2,2};
        printf("makesquare=%d\n",makesquare(V1));
        
        vector<int> V2={3,3,3,3,4};
        printf("makesquare=%d\n",makesquare(V2));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
