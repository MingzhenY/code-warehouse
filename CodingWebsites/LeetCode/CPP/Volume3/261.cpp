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
    int Parts;
    vector<int> F;
    int find(int x){
        return x == F[x] ? x : F[x] = find(F[x]);
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        F = vector<int>(n);
        if(edges.size() != n - 1) return false;
        Parts = n;
        for(int i = 0 ; i < n ; ++i) F[i] = i;
        for(auto x:edges){
            int A = find(x.first);
            int B = find(x.second);
            if(A == B) return false;
            F[A] = B;
            --Parts;
        }
        return Parts == 1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
