#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int N = 1 << n;
        vector<vector<int>> ANS;
        for(int i = 0 ; i < N ; ++i){
            vector<int> ans;
            for(int C = i , j = 0 ; j < n ; ++j, C >>= 1){
                if(C & 1) ans.push_back(nums[j]);
            }
            ANS.push_back(ans);
        }
        return ANS;
    }
    void Test(){
        int A[] = {1,2,3};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        vector<vector<int>> ANS = subsets(V);
        for(auto line : ANS){
            for(auto x : line){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
