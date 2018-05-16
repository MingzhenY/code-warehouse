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
    vector<int> singleNumber(vector<int>& nums) {
        //Lets assume the two numbers are A and B
        int S = 0;// S = A ^ B;
        for(auto x:nums) S ^= x;
        //pick any bit in S
        S = S & -S;//take the lowest bit
        int L = 0 , R = 0;
        for(auto x:nums){
            //if that bit is set, put in group L
            //else put in group R
            //A and B will fall in different groups
            //so xor each group of numbers will get A and B
            if(x & S) L ^= x;
            else R ^= x;
        }
        return {L,R};
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
