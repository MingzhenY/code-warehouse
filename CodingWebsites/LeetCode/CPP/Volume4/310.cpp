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
    struct Node{
        list<int> L;//the list of edges
        int d;
        bool vis;
        Node(){
            d = INT_MAX;
            vis = false;
        }
    };
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<Node> V(n);
        for(auto x:edges){
            V[x.first].L.push_back(x.second);
            V[x.second].L.push_back(x.first);
        }
        queue<int> Q;
        for(int i = 0 ; i < n ; ++i){
            if(V[i].L.size() <= 1){
                V[i].d = 0;
                V[i].vis = true;
                Q.push(i);
            }
        }
        int Maxd = 0;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            for(auto to:V[cnt].L){
                if(!V[to].vis){
                    V[to].vis = true;
                    V[to].d = V[cnt].d + 1;
                    if(V[to].d > Maxd) Maxd = V[to].d;
                    Q.push(to);
                }
            }
        }
        vector<int> ret;
        for(int i = 0 ; i < n ; ++i){
            if(V[i].d == Maxd) ret.push_back(i);
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
