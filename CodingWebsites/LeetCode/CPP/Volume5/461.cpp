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
public:
    int hammingDistance(int x, int y) {
        int X = x ^ y, ret = 0;
        while(X){
            ret += X & 1;
            X >>= 1;
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
