#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int digit[10],di = 0;
        int sign = x >= 0;
        long long X = x;
        if(X >= 0){
            sign = 0;
        }
        else{
            sign = 1;
            X = -X;
        }
        while(X){
            digit[di++] = X % 10;
            X /= 10;
        }
        long long ANS = 0;
        for(int i = 0 ; i < di ; ++i) ANS = 10 * ANS + digit[i];
        if(sign) ANS = - ANS;
        if(ANS >= (1LL<<31) || ANS < -(1LL << 31)){
            ANS = 0;
        }
        return (int) ANS;
    }
    void Test(){
        cout<<reverse(1563847412)<<endl;
        cout<<reverse(-123)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
