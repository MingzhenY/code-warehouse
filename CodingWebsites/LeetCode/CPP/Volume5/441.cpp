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
    #define LL long long
public:
    int arrangeCoins(int n) {
        LL L = 0, R = 1 << 16;
        while(L + 1 < R){//[L,R) last k*(k+1)/2 <= n
            LL M = (L + R) >> 1;
            if(M * (M + 1) / 2 <= n)
                L = M;
            else
                R = M;
        }
        return L;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
