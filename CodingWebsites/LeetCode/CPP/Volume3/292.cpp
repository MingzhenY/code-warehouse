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
    bool canWinNim(int n) {
        bool F[] = {false,true,true,true,false};
        return n % 4;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
