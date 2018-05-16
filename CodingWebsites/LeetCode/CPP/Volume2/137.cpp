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
/*
 Note: Even binary search TLE
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Use two bits for each bit
        int B1 = 0, B0 = 0;
        for(auto x:nums){
            //Count bits in each bit
            B1 = B1 ^ (B0 & x);
            B0 = B0 ^ x;
            //apply mod 3 to each counter
            int X = B0 & B1;
            B0 = B0 & ~X;
            B1 = B1 & ~X;
            
            /*
             Method 1:
             int nB1,nB0;
             nB0 = (x&~B0&~B1) | (~x&~B1&B0);
             nB1 = (x&~B1&B0) | (~x&B1&~B0);
             B0 = nB0;
             B1 = nB1;*/
        }
        return B0;
    }
    void Test(){
        int A[]={1,1,1,3,3,3,4,4,4,2,2,2,7};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<singleNumber(V)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
