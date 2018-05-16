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
/*
 Find the least numebr of perfect square numbers(1,4,9...) which sum to n.
 There is a conclusion that 4 perfect square numbers are enough to sum to any number.
 */
class Solution {
    vector<long long> SQ;
    int Sn;
public:
    int numSquares(int n) {
        Sn = sqrt(n);
        SQ = vector<long long>(Sn + 1,0);
        for(int i = 0 ; i <= Sn ; ++i)
            SQ[i] = i * i;
        if(Sum1(n)) return 1;
        if(Sum2(n)) return 2;
        if(Sum3(n)) return 3;
        return 4;
    }
    bool Sum1(int n){//O(1)
        int q = sqrt(n);
        return n == q * q;
    }
    bool Sum2(int n){//O(sqrt(n))
        int L = 1 , R = sqrt(n);//[L,R]
        while(L <= R){
            long long Sum = SQ[L] + SQ[R];
            if(Sum == n) return true;
            if(Sum > n) --R;
            else ++L;
        }
        return false;
    }
    bool Sum3(int n){//O(sqrt(n)^2)
        int q = sqrt(n);
        for(int i = 1 ; i <= q ; ++i)
            if(Sum2(n - SQ[i])) return true;
        return false;
    }
    void Test(){
        cout<<numSquares(12)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
