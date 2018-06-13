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
    int getSum(int a, int b) {
        int H1 = a & b;
        int H0 = a ^ b;
        return H1 ? getSum(H1<<1,H0) : H0;
    }
    void Test(){
        vector<vector<int>> nums = {
            {1,2},
            {3,7},
            {11,13}
        };
        for(auto x:nums){
            printf("%d + %d = %d\n",x[0],x[1],getSum(x[0],x[1]));
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
