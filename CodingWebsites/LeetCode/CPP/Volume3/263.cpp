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
    bool isUgly(int num) {
        if(!num) return false;
        while(~num & 1)  num >>= 1;
        while(num % 3) num /= 3;
        while(num % 5) num /= 5;
        return num == 1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
