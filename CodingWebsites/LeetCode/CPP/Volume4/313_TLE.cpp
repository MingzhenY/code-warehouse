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
#define LL long long
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<LL> Q;
        map<LL,bool> InQ;
        Q.push(-1LL);
        int I = 0;
        while(++I){
            LL x = Q.top(); Q.pop();
            if(I == n) return -x;
            for(auto p : primes){
                int newx = x * p;
                if(!InQ.count(newx)){
                    Q.push(newx);
                    InQ[newx] = true;
                }
            }
        }
        return -1;
    }
    void Test(){
        vector<int> primes = {2,7,13,19};
        for(int i = 1 ; i <= 20 ; ++i){
            printf("f(%d) = %d\n",i,nthSuperUglyNumber(i,primes));
        }

    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
