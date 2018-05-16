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
    bool canJump(vector<int>& nums) {
        int MaxJump = 0;
        int N = nums.size();
        for(int i = 0 ; i <= MaxJump && i < N; ++i){
            int CurMaxJump = i + nums[i];
            if(CurMaxJump > MaxJump) MaxJump = CurMaxJump;
        }
        return MaxJump >= N - 1;
    }
    void Test(){
        int A[]={0};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<canJump(V)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
