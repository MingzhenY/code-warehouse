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

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        sum = vector<int>(nums.size()+1,0);
        for(int i = 0 ; i < nums.size() ; ++i)
            sum[i + 1] = sum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
int main(){
    Solution S;
    S.Test();
	return 0;
}
