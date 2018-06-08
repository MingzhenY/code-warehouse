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
        int ret = 1;
        while(k){
            if(k & 1) ret *= a;
            a *= a;
            k >>= 1;
        }
        return ret;
    }
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n % 3 == 0)
            return pow(3,n/3);
        if(n % 3 == 1)
            return pow(3,n/3-1)*4;
        return pow(3,n/3) * 2;
    }
    void Test(){
        printf("%d\n",integerBreak(10));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
