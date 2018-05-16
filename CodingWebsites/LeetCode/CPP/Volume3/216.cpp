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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ANS;
        vector<int> V;
        F(ANS,V,k,9,n);
        return ANS;
    }
    void F(vector<vector<int>> &ANS, vector<int> &V, int k, int digit,int target){
        if(target < 0) return;
        if(k == 0){
            if(target == 0)
                ANS.push_back(V);
            return;
        }
        for(int t = digit; t >= 1 ; t--){
            V.push_back(t);
            F(ANS,V,k - 1,t - 1,target - t);
            V.erase(V.end() - 1);
        }
    }
    void Test(){
        vector<vector<int>> A = combinationSum3(3,9);
        for(auto line : A){
            for(auto x:line){
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
