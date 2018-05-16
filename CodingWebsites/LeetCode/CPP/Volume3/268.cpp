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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Xofn = -1;
        for(int i = 0 ; i < n ; ++i){
            while(nums[i] != n && nums[i] != i){
                swap(nums[i],nums[nums[i]]);
            }
            if(nums[i] == n) Xofn = i;
        }
        return ~Xofn ? Xofn : n;
    }
    void Test(){
        vector<int> V = {9,6,4,2,3,5,7,0,1};
        cout<<missingNumber(V)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
