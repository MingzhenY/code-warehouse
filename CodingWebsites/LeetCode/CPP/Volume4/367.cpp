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
    #define LL long long
public:
    bool isPerfectSquare(int num) {
        LL L = 0, R = INT_MAX;//[L,R)
        while(L + 1 < R){//find last <= num
            LL M = (L + R) / 2;
            if(M * M <= num)
                L = M;
            else
                R = M;
        }
        return L * L == num;
    }
    void Test(){
        printf("%d\n",isPerfectSquare(16));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
