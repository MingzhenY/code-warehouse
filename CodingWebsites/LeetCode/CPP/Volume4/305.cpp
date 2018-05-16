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
    //use union find
    map<pair<int,int>,pair<int,int>> F;
    pair<int,int> Find(pair<int,int> x){
        return x == F[x] ? x : F[x] = Find(F[x]);
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int A = 0;
        vector<int> ret;
        for(auto P : positions){
            if(!F.count(P)){
                F[P] = P;
                ++A;
                int dx[] = {-1,0,1,0};
                int dy[] = {0,1,0,-1};
                for(int k = 0 ; k < 4 ; ++k){
                    int nx = P.first + dx[k], ny = P.second + dy[k];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       F.count(pair<int,int>(nx,ny))){
                        pair<int,int> L = Find(pair<int,int>(nx,ny));
                        pair<int,int> R = Find(P);
                        if(L != P){
                            --A;
                            F[L] = P;
                        }
                    }
                }
            }
            ret.push_back(A);
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
