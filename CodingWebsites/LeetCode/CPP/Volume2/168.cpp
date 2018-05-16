#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
#define LL long long
public:
    string convertToTitle(int n) {
        int L = 0;
        LL p26 = 1;
        while(n >= p26){
            n -= p26;
            ++L;
            p26 *= 26;
        }
        return convert(L,n);
    }
    string convert(int L, int n){
        string ANS(L,' ');
        for(int i = 0 ; i < L ; i++){
            ANS[L-i-1] = 'A' + (n % 26);
            n /= 26;
        }
        return ANS;
    }
    void Test(){
        cout<<convertToTitle(1)<<endl;
        cout<<convertToTitle(28)<<endl;
        cout<<convertToTitle(1000000001)<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
