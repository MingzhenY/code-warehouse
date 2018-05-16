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
    int mySqrt(int x) {
        long long L = 0 , R = 1LL << 31 , M;
        while(L + 1 < R){//[L,R)  last k that k * k <= x
            M = (L + R) >> 1;
            if(M * M <= x) L = M;
            else R = M;
        }
        return int(L);
    }
    void Test(){
        cout<<mySqrt(35)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
