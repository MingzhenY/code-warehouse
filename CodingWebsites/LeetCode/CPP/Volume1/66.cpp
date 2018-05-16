#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> D(n+1,0);
        for(int i = 0 ; i < n ; ++i){
            D[i] = digits[n - i - 1];
        }
        ++D[0];
        for(int i = 0 ; i < n ; ++i){
            if(D[i] > 9){
                D[i + 1] += D[i] / 10;
                D[i] %= 10;
            }
        }
        if(D[n] != 0) ++n;
        vector<int> A(n,0);
        for(int i = 0 ; i < n ; ++i) A[i] = D[n - i - 1];
        return A;
    }
    void Test(){
        int Number[] = {9,9,9};
        vector<int> A(Number,Number+sizeof(Number)/sizeof(Number[0]));
        vector<int> ANS = plusOne(A);
        for(auto x:ANS){
            printf("%d",x);
        }
        printf("\n");
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
