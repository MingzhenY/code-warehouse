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
    struct Node{
        int H;//Current Health
        int L;//Lowest Health
        Node(int H = 0, int L = 0):H(H),L(L){}
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        if(!M) return 0;
        int N = dungeon[0].size();
        if(!N) return 0;
        vector<vector<Node> > D(M+1,vector<Node> (N+1));
        for(int i = 1 ; i <= M ; i++){
            for(int j = 1 ; j <= N ; j++){
                //Only Look at dungeon[i-1][j] and dungeon[i][j-1]
                //doesn't have enough info to know which to choose
            }
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
