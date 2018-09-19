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

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int X;
        do{
            //X <- [0,48]
            X = (rand7() - 1) * 7 + rand7() - 1;
        }while(X >= 40);
        return X % 10 + 1;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
