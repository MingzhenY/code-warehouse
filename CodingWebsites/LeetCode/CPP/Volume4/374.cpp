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

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int L = 1, R = n;//[L,R]
        while(L < R){//first >= v
            int M = L + ((R - L) >> 1);
            if(guess(M) <= 0)
                R = M;
            else
                L = M + 1;
        }
        return L;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
