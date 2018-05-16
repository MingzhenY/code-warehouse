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
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        if(!N) return 0;
        int MinSoFar = 0;
        int SumSoFar = 0;
        int ANS = nums[0];
        for(int i = 0 ; i < N ; ++i){
            SumSoFar += nums[i];
            int CurANS = SumSoFar - MinSoFar;
            if(CurANS > ANS){
                ANS = CurANS;
            }
            MinSoFar = min(MinSoFar,SumSoFar);
        }
        return ANS;
    }
    void Test(){
        int A[] = {-2,1,-3,4,-1,2,1,-5,4};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        int ANS = maxSubArray(V);
        cout<<ANS<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
