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
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(auto x:nums){
            if(S.count(x))
                return true;
            S.insert(x);
        }
        return false;
    }
    void Test(){
        vector<int> nums = {2,6,7,4,1,5,9,7};
        cout<<containsDuplicate(nums)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
