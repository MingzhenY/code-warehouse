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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> MinEnd(1,INT_MAX + 1);
        //MinEnd[k] = smallest ending of LIS of length k
        for(int i = 0 ; i < n ; ++i){
            int L = 0, R = MinEnd.size();//[L,i) last < nums[i];
            while(L + 1 < R){
                int M = (L + R) >> 1;
                if(MinEnd[M] < nums[i]) L = M;
                else R = M;
            }
            if(R == MinEnd.size()) MinEnd.push_back(nums[i]);
            else if(nums[i] < MinEnd[R]) MinEnd[R] = nums[i];
        }
        return MinEnd.size() - 1;
    }
    void Test(){
        vector<int> V = {1,9,2,8,3,7,4,6,5};
        cout<<lengthOfLIS(V)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
