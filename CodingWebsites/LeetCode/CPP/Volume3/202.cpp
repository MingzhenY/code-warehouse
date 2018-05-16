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
    bool isHappy(int n) {
        LL L = n , R = n;
        //Use slow/fast pointer to detect circle
        while(1){
            L = F(L);
            R = F(R);
            R = F(R);
            if(R == 1) return true;
            if(L == R) return false;
        }
    }
    LL F(LL n){
        LL ANS = 0;
        while(n){
            int x = n % 10;
            n /= 10;
            ANS += x * x;
        }
        return ANS;
    }
    void Test(){
        for(int i = 1 ; i < 10 ; i++){
            cout<<i<<":"<<isHappy(i)<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
