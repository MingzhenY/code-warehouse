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
    //Could you solve it without loops/recursion? 
public:
    bool isPowerOfFour(int num) {
        if(num & 0xaaaaaaaa) return false;
        return num && num == (num & -num);
    }
    void Test(){
        for(int i = 0 ; i < 20 ; ++i){
            printf("%d - %d\n",i,isPowerOfFour(i));
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
