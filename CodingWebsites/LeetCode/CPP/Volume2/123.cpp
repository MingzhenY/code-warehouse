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
using namespace std;
/*
 Solution1:
 find max profit with [1..k] and [k..N]
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(!N) return 0;
        vector<int> L(N),R(N);
        
        {//
            int MinSoFar = prices[0];
            for(int i = 0 ; i < N ; i++){
                L[i] = max(i ? L[i - 1] : 0,prices[i] - MinSoFar);
                MinSoFar = min(MinSoFar,prices[i]);
                printf("L[%d]=%d\n",i,L[i]);
            }
        }
        {//
            int MaxSoFar = prices[N - 1];
            for(int i = N - 1 ; i >= 0 ; i--){
                R[i] = max(i + 1 < N ? R[i + 1] : 0,MaxSoFar - prices[i]);
                MaxSoFar = max(MaxSoFar,prices[i]);
                printf("R[%d]=%d\n",i,R[i]);
            }
        }
        int ANS = max(L[N-1],R[0]);
        for(int i = 1 ; i < N ; ++i){
            int C = L[i - 1] + R[i];
            ANS = max(ANS,C);
        }
        return ANS;
    }
    void Test(){
        int A[] = {3,2,6,5,0,3};
        vector<int> V(A,A+sizeof(A)/sizeof(A[0]));
        cout<<maxProfit(V)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
