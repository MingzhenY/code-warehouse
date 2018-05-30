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
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
    void Test(){
        printf("%d\n",bulbSwitch(3));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
