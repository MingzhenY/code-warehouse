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
    int rangeBitwiseAnd(int m, int n) {
        int ANS = 0;
        for(int i = 0 ; i < 31 ; i++){
            if(m + MaxLeap(m,i) >= n){
                ANS |= 1 << i;
            }
        }
        return ANS;
    }
    int MaxLeap(int start, int k){
        int M = 1 << k;
        if(start & M){
            return M - 1 - (start & (M - 1));
        }
        else return -1;
    }
    void Test(){
        cout<<rangeBitwiseAnd(5,7)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
