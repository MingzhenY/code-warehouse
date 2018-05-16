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
#include <ctime>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t A = 0;
        for(int i = 0 ; i < 32 ; i++){
            A = (A << 1) | (n & 1);
            n >>= 1;
        }
        return A;
    }
    void Test(){
        srand(time(NULL));
        int x = rand();
        ShowBits(x);
        ShowBits(reverseBits(x));
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
