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
/*
Segment Tree AC

*/
class Solution {
    int N;
    vector<int> Sum;
    void Init(int len){
        N = 1;
        while(N < len + 2)
            N <<= 1;
        Sum = vector<int>(2*N,0);
    }
    void Update(int L, int R, int V){
        for(int s = N + L - 1, t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1, t >>= 1){
            if(~s & 1)
                Sum[s ^ 1] += V;
            if( t & 1)
                Sum[t ^ 1] += V;
        }
    }
    void PushDown(){
        for(int i = 1 ; i < N ; ++i){
            Sum[i << 1] += Sum[i];
            Sum[i <<1 | 1] += Sum[i];
        }
    }
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        Init(length);
        for(auto x : updates){
            Update(x[0] + 1,x[1] + 1,x[2]);
        }
        PushDown();
        vector<int> ret;
        for(int i = 1 ; i <= length ; ++i){
            ret.push_back(Sum[N + i]);
        }
        return ret;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
