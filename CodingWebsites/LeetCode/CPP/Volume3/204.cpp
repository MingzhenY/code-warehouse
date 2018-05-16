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
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> D(n,-1);
        int ANS = 0;
        for(int i = 2 ; i < n ; i++){
            if(D[i] != -1) continue;
            for(int j = i ; j < n ; j += i){
                D[j] = i;
            }
            ++ANS;
        }
        return ANS;
    }
    void Test(){
        cout<<countPrimes(100)<<endl;
    }
};



int main(){
    Solution2 S;
    S.Test();
	return 0;
}
