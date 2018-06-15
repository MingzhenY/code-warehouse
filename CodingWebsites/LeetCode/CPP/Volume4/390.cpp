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
    int lastRemaining(int n) {
        int a = 1, b = 0, t = 0;
        //list = filter (<=n) [ax+b|x<-[1..]]
        //len(list) = (n-b)/a;
        while(2 * a + b <= n){
            //while the second number is <= n
            //remove numbers
            if(++t % 2 == 0 && ((n-b)/a) % 2 == 0)
                b -= a;
            a *= 2;
            //printf("%dx + %d\n",a,b);
        }
        return a + b;
    }
    void Test(){
        printf("%d\n",lastRemaining(9));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
