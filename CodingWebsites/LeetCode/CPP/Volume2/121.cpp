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
        int N = prices.size();
        if(!N) return 0;
        int MinValueUpToNow = prices[0];
        int ANS = 0;
        for(int i = 0 ; i < N ; ++i){
            if(prices[i] - MinValueUpToNow > ANS){
                ANS = prices[i] - MinValueUpToNow;
            }
            MinValueUpToNow = min(MinValueUpToNow,prices[i]);
        }
        return ANS;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
