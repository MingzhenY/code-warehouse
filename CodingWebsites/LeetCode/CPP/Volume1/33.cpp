#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        if(!N) return -1;
        
        
    }
    
    void Test(){
        int S[] = {4,5,6,7,8,9,1,2,3};
        vector<int> Nums(S,S+sizeof(S)/sizeof(S[0]));
        cout<<search4(Nums,1)<<endl; //Should return 3
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
