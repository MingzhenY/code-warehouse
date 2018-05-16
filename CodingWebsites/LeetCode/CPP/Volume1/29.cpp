#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
#define LL long long
#define MAX_INT 2147483647
public:
    int divide(int dividend, int divisor) {
        LL A = dividend, B = divisor;
        LL ANS;
        if(A < 0 && B < 0) ANS = absdivide(-A,-B);
        else if(B < 0) ANS = - absdivide(A, -B);
        else if(A < 0) ANS = - absdivide(-A,B);
        else ANS = absdivide(A,B);
        if(ANS > 2147483647 || ANS < -2147483648) ANS = MAX_INT;
        return ANS;
    }
    LL absdivide(LL dividend, LL divisor){
        if(divisor == 0) return MAX_INT;
        LL ANS = 0;
        LL x = 1;
        while(divisor < dividend) x <<= 1, divisor <<= 1;
        while(x){
            if(dividend >= divisor){
                dividend -= divisor;
                ANS = ANS | x;
            }
            x >>= 1;
            divisor >>= 1;
        }
        return ANS;
    }
    void Test(){
        cout<<divide(12,-5)<<endl;
        cout<<absdivide(2147483647LL,1)<<endl;
        cout<<absdivide(2147483648LL,1)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
