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
#define INF INT_MAX
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int M = rooms.size();
        if(!M) return;
        int N = rooms[0].size();
        if(!N) return;
        queue<pair<int,int>> Q;
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(rooms[i][j] == 0){
                    Q.push(pair<int,int>(i,j));
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!Q.empty()){
            pair<int,int> P = Q.front();Q.pop();
            for(int k = 0 ; k < 4 ; ++k){
                int nx = P.first + dx[k], ny = P.second +dy[k];
                if(nx >= 0 && nx < M && ny >= 0 && ny < N &&
                   rooms[nx][ny] == INF){
                    rooms[nx][ny] = rooms[P.first][P.second] + 1;
                    Q.push(pair<int,int>(nx,ny));
                }
            }
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
