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
    map<int,int> M;
    int F(int n){
        if(M.count(n))
            return M[n];
        if(n <= 2)
            return M[n] = n - 1;
        if(n % 2 == 1){
            return M[n] = 2 + min(F(n / 2), F(n / 2 + 1));
        }
        else{
            return M[n] = 1 + F(n / 2);
        }
    }
public:
    int integerReplacement(int n) {
        return F(n);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
