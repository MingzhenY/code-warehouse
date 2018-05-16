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
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> D(n,0);
        D[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            D[i] = max(D[i - 1], nums[i] + D[i - 2]);
        }
        return D[n - 1];
    }
    void Test(){
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
