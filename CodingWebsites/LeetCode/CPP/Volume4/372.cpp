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
    int pow(int a,int k){
        int ANS = 1;
        while(k){
            if(k & 1)
                ANS = ANS * a % 1337;
            a = a * a % 1337;
            k >>= 1;
        }
        return ANS;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ANS = 1, N = b.size();
        // a^(10x + y) = (a^x)^10 * a^y
        for(int i = 0 ; i < N ; ++i){
            ANS = pow(ANS,10) * pow(a % 1337,b[i]) % 1337;
        }
        return ANS;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
