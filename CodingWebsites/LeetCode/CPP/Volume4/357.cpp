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
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10)
            n = 10;
        int D[11];
        D[0] = 1;
        D[1] = 9;
        for(int i = 2 ; i <= 10 ; ++i){
            D[i] = D[i-1] * (11 - i);
        }
        int ANS = 0;
        for(int i = 0 ; i <= n ; ++i)
            ANS += D[i];
        return ANS;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
