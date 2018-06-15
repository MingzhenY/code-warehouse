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
    int findNthDigit(int n) {
        //x * t
        //9 * 1
        //90 * 2
        //900 * 3
        // 9000 * 4
        long long x,t,sum;
        for(x = 9, t = 1, sum = 0; n > x * t && (sum += x); x *= 10, ++t)
            n -= x * t;
        long long v = sum + (n - 1) / t + 1;
        for(int i = t - 1 - (n - 1) % t ; i > 0 ; --i)
            v /= 10;
        return v % 10;
    }
    void Test(){
        printf("%d\n",findNthDigit(190));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
