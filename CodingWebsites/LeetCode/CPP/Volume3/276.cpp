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
    int numWays(int n, int k) {
        if(!n) return 0;
        int F[2],G[2];
        F[1] = k, G[1] = 0;
        for(int i = 2 ; i <= n ; ++i){
            F[i&1] = (F[~i&1] + G[~i&1]) * (k - 1);
            G[i&1] = F[~i&1];
        }
        return F[n&1] + G[n&1];
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
