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
    void moveZeroes(vector<int>& nums) {
        int Z = 0, NZ = 0, N = nums.size();
        while(1){
            //find the first zero
            while(Z < N && nums[Z]) ++Z;
            //find the first non-zero after Z
            NZ = Z;
            while(NZ < N && !nums[NZ]) ++NZ;
            //break if work done
            if(NZ == N) break;
            //swap values
            swap(nums[Z],nums[NZ]);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
