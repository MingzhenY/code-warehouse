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
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int A = 0;
        for(auto x:nums){
            A = A ^ x;
        }
        return A;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
