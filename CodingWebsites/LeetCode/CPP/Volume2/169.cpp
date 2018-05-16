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
    int majorityElement(vector<int>& nums) {
        int V, C = 0;
        for(auto x:nums){
            if(C == 0 || V == x){
                V = x;
                ++C;
            }
            else{
                --C;
            }
        }
        return V;
    }
    void Test(){
        vector<int> nums = {1,2,3,4,5,5,5,5,5,5,5};
        cout<<majorityElement(nums)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
