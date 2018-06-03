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
    vector<int> F;
    int Find(int x){
        return x == F[x] ? x : F[x] = Find(F[x]);
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        F = vector<int>(n);
        for(int i = 0 ; i < n ; ++i) 
            F[i] = i;
        int ANS = n;
        for(auto e : edges){
            int x = Find(e.first), y = Find(e.second);
            if(x != y){
                F[x] = y;
                --ANS;
            }
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
