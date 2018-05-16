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
        int n = citations.size();
        int L = 0, R = n;//[L,R)
        while(L + 1 < R){
            int M = (L + R) >> 1;
            int H = n - M;
            //if(citations[M - 1] <= H && citations[M] >= H) return M;
            if(citations[M - 1] <= H) L = M;
            else R = M;
        }
        return n > L && citations[L] >= n - L ? n - L : 0;
    }
    void Test(){
        vector<int> C = {1,1,2,3,4,5,7};
        cout<<hIndex(C)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
