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
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int C2 = 0, C5 = 0;
        int n2 = n, n5 = n;
        while(n2 > 0){
            C2 += n2 /= 2;
        }
        while(n5 > 0){
            C5 += n5 /= 5;
        }
        return min(C2,C5);
    }
    void Test(){
        cout<<trailingZeroes(10)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
