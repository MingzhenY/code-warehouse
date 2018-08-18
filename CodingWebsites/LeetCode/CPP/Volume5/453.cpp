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
    int minMoves(vector<int>& nums) {
        int N = nums.size();
        if(!N) return 0;
        
        int Min = nums[0];
        for(auto x : nums)
            Min = min(Min,x);
        int ret = 0;
        for(auto x : nums)
            ret += x - Min;
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
