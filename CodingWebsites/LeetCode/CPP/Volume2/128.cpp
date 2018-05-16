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
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for(auto x:nums) S.insert(x);
        int MaxL = 0;
        for(auto x:nums) {
            if(S.count(x - 1)) continue;
            int CurL = 1;
            int NextV = x + 1;
            while(S.count(NextV)){
                CurL++;
                NextV++;
            }
            if(CurL > MaxL) MaxL = CurL;
        }
        return MaxL;
    }
    void Test(){
        int A[]={100, 4, 200, 1, 3, 2};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<longestConsecutive(V)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
