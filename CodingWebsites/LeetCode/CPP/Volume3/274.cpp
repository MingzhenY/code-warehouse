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
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size(), MinSoFar = INT_MAX;
        int ANS = 0;
        for(int i = n - 1 , H = 1; i >= 0 ; --i, ++H){
            MinSoFar = min(MinSoFar,citations[i]);
            if(MinSoFar >= H && (!i || citations[i - 1] <= H)){
                ANS = H;
            }
        }
        return ANS;
    }
    void Test(){
        vector<int> C = {0,1,3,5,6};
        cout<<hIndex(C)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
