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
    int thirdMax(vector<int>& nums) {
        set<int> S;
        for(auto x : nums){
            S.insert(x);
            while(S.size() > 3){
                S.erase(S.begin());
            }
        }
        if(S.size() == 3)
            return *S.begin();
        else if(S.size() > 0)
            return *S.rbegin();
        else return -1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
