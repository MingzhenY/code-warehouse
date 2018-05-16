#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


class Solution {
public:
    int sgn(double x){return (x > -1e-9) - (x < 1e-9);}
    double myPow(double x, int n) {
        if(sgn(x) == 0) return 0.0;
        long long N;
        if(n < 0) x = 1.0/x , N = -(long long)n;
        else N = n;
        double ANS = 1.0;
        while(N){
            if(N & 1) ANS *= x;
            x = x * x;
            N >>= 1;
        }
        return ANS;
    }
    void Test(){
        cout<<myPow(1.0,-2147483648)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
