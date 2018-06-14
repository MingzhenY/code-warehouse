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
    vector<int> V;
public:
    Solution(vector<int> nums) {
        V = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return V;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int N = V.size();
        vector<int> ret;
        vector<int> D(N);
        for(int i = 0 ; i < N ; ++i)
            D[i] = i;
        for(int i = 0 ; i < N ; ++i){
            //[i,N)
            int j = rand() % (N - i) + i;
            int t = D[j];
            D[j] = D[i];
            D[i] = t;
            
            ret.push_back(V[D[i]]);
        }
        return ret;
    }
    void Test(){
        
    }
};

int main(){
    Solution S({1,2,3});
    S.Test();
	return 0;
}
