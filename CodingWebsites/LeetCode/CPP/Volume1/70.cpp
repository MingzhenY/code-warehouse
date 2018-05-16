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
    int climbStairs(int n) {
        int A = 0, B = 1, C = 1;//B = F(0)
        while(n--){
            A = B;
            B = C;
            C = A + B;
        }
        return B;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
