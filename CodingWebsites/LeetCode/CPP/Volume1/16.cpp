#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
private:
    int N;
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        N = nums.size();
        int ANS = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < N ; ++i){
            int T2 = target - nums[i];
            int L = 0 , R = N - 1;
            while(L < R){
                //printf("(L,R)=(%d,%d)\n",L,R);
                if(L == i){
                    ++L;continue;
                }
                if(R == i){
                    --R;continue;
                }
                int Sum2 = nums[L] + nums[R];
                
                
                //Record Answer
                int CntSum3 = nums[i] + Sum2;
                if(abs(CntSum3 - target) < abs(ANS - target)){
                    ANS = CntSum3;
                }
                if(ANS == target) return target;
                
                if(Sum2 < T2){
                    ++L;
                }
                else if(Sum2 > T2){
                    --R;
                }
            }
        }
        return ANS;
    }
    void Test(){
        int Data[] = {-1,2,1,-4};
        vector<int> V(Data,Data + sizeof(Data)/sizeof(Data[0]));
        cout<<threeSumClosest(V,1)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
