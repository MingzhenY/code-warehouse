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
    vector<vector<int>> combine(int n, int k) {
        if(n > 25) return vector<vector<int>>();
        
        vector<vector<int>> ANS;
        int N = 1 << n;
        for(int i = 0 ; i < N ; ++i){
            if(countBit(i) == k){
                vector<int> ans;
                int C = i;
                for(int j = 1 ; j <= n ; ++j, C >>= 1){
                    if(C & 1) ans.push_back(j);
                }
                ANS.push_back(ans);
            }
        }
        return ANS;
    }
    int countBit(int x){
        x = (x & 0x55555555) + ((x & 0xAAAAAAAA) >> 1);
        x = (x & 0x33333333) + ((x & 0xCCCCCCCC) >> 2);
        x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
        x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
        x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
        return x;
    }
    void Test(){
        vector<vector<int>> ANS = combine(4,2);
        for(auto line : ANS){
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
