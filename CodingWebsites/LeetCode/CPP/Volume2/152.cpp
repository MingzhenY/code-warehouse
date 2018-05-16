#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MaxSoFar = 0 , MinSoFar = 0;
        int Max = (1 << 31);
        for(int i = 0 ; i < nums.size() ; i++){
            if(i){
                if(nums[i] > 0) {
                    int nMaxSoFar = max(nums[i],MaxSoFar * nums[i]);
                    int nMinSoFar = min(nums[i],MinSoFar * nums[i]);
                    MaxSoFar = nMaxSoFar;
                    MinSoFar = nMinSoFar;
                }
                else{
                   int nMaxSoFar = max(nums[i],MinSoFar * nums[i]);
                   int nMinSoFar = min(nums[i],MaxSoFar * nums[i]);
                    MaxSoFar = nMaxSoFar;
                    MinSoFar = nMinSoFar;
                }
            }else{
                MaxSoFar = MinSoFar = nums[i];
            }
            if (MaxSoFar > Max) Max = MaxSoFar;
            printf("%d:(%d,%d)\n",i,MinSoFar,MaxSoFar);
        }
        return Max;
    }
    void Test(){
        int A[]={-4,-3,-2};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<maxProduct(V)<<endl;
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
