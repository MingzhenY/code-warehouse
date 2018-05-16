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
public:
    int hammingWeight(uint32_t n) {
        n = ((n & 0xAAAAAAAAu) >> 1) + (n & 0x55555555u);
        n = ((n & 0xCCCCCCCCu) >> 2) + (n & 0x33333333u);
        n = ((n & 0xf0f0f0f0u) >> 4) + (n & 0x0f0f0f0fu);
        n = ((n & 0xff00ff00u) >> 8) + (n & 0x00ff00ffu);
        n = ((n & 0xffff0000u) >> 16) + (n & 0x0000ffffu);
        return n;
    }
    void Test(){
        srand(time(NULL));
        int x = rand();
        ShowBits(x);
        cout<<hammingWeight(x)<<endl;
    }
    void ShowBits(uint32_t n){
        uint32_t Mask = 1u << 31;
        for(int i = 31 ; i >= 0 ; i--){
            printf("%d",(n & Mask)>>i);
            Mask >>= 1;
        }
        printf("\n");
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
