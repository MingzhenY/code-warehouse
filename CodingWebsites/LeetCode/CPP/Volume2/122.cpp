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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //This solution is O(n^2), however, O(n) solution exists.
        int N = prices.size();
        if(!N) return 0;
        vector<int> D(N);//D[i] = best profit [0,i]
        D[0] = 0;
        for(int i = 1 ; i < N ; ++i){
            D[i] = max(0,prices[i] - prices[0]);
            for(int k = 0 ; k < i ; ++k){
                //[0,k] + [k + 1, i]
                int tempProfit = D[k] + max(0,prices[i] - prices[k+1]);
                if(tempProfit > D[i]){
                    D[i] = tempProfit;
                }
            }
        }
        return D[N - 1];
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
