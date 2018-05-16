#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
//线段树 - O(nlogn)
//特殊解法 - O(n)


class Solution {
private:
    int N;
public:
    int jump(vector<int> &nums){
        int n = nums.size();
        N = 1;
        while(N < n + 2) N <<= 1;
        vector<int> Min(N << 1, n);
        Update(Min,1,1,0);
        for(int i = 0 ; i < n ; ++i){
            int I = i + 1;
            Update(Min,I,min(I + nums[i],n),Query(Min,I) + 1);
        }
        return Query(Min,n);
    }
    void Update(vector<int> &Min,int L,int R,int V){
        //printf("Update(%d,%d,%d)\n",L,R,V);
        for(int s = N + L - 1 , t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1, t >>= 1){
            if(~s & 1)
                Min[s ^ 1] = min(Min[s ^ 1],V);
            if( t & 1)
                Min[t ^ 1] = min(Min[t ^ 1],V);
        }
    }
    int Query(vector<int> &Min,int X){
        int ANS = N;
        for(int s = N + X ; s ; s >>= 1){
            ANS = min(ANS,Min[s]);
        }
        return ANS;
    }
    
    
    /*
    int jumpTLE(vector<int>& nums) {
        int N = nums.size();
        vector<int> jumps(N,-1);
        jumps[0] = 0;
        for(int i = 0 ; i < N ; ++i){
            if(jumps[i] >= 0){
                for(int j = 1 ; j <= nums[i] && i + j < N ; ++j){
                    if(-1 == jumps[i + j] || jumps[i + j] > jumps[i]){
                        jumps[i + j] = jumps[i] + 1;
                    }
                }
            }
        }
        return jumps[N - 1];
    }*/
    void Test(){
        int A[] = {2,3,1,1,4};
        vector<int> nums(A,A+sizeof(A)/sizeof(int));
        cout<<jump(nums)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
