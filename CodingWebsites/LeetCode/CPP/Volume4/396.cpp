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
    int maxRotateFunction(vector<int>& A) {
        int L1,R1,L0,R0,N = A.size();
        L0 = L1 = R0 = R1 = 0;
        for(int i = 0 ; i < N ; ++i){
            L0 += A[i];
            L1 += i * A[i];
        }
        int ANS = L1;
        for(int k = N - 1 ; k > 0 ; --k){
            //Left: [0,k), Right: [k,N)
            L0 -= A[k];
            L1 = L1 - (N - 1) * A[k] + L0;
            
            R1 += R0;
            R0 += A[k];
            
            ANS = max(ANS,L1 + R1);
        }
        return ANS;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
