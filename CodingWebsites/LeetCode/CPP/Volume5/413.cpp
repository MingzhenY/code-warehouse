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
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size(), ANS = 0;
        for(int i = 0 ; i < N - 1 ;){
            int step = A[i + 1] - A[i];
            int R = i + 1;
            while(R + 1 < N && A[R + 1] - A[R] == step)
                ++R;
            //[L,R]
            ANS += (R - i) * (R - i - 1) / 2;
            i = R;
        }
    return ANS;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
