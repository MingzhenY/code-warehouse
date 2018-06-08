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

class MovingAverage {
    #define LL long long
    LL Sum;
    int S;
    queue<int> Q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        Sum = 0;
        S = size;
        Q = queue<int>();
    }
    
    double next(int val) {
        Sum += val;
        Q.push(val);
        if(Q.size() > S){
            Sum -= Q.front();
            Q.pop();
        }
        return Sum * 1.0 / Q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
