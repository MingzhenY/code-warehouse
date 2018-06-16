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
    queue<pair<int,int>> Q;
    //set<pair<int,int>> S;
    vector<vector<int>> Water;
    void AddtoQueue(pair<int,int> p){
        //if(!S.count(p)){
            Q.push(p);
        //    S.insert(p);
        //}
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(!M) return {};
        int N = matrix[0].size();
        
        int P=1,A=2;
        Water = vector<vector<int>>(M,vector<int>(N,0));
        
        pair<int,int> p;
        //Add first and last row
        for(int j = 0 ; j < N ; ++j){
            p = make_pair(0,j);
            AddtoQueue(p);
            Water[p.first][p.second] |= P;
            
            p = make_pair(M-1,j);
            AddtoQueue(p);
            Water[p.first][p.second] |= A;
        }
        //Add first and last column
        for(int i = 0 ; i < M ; ++i){
            p = make_pair(i,0);
            AddtoQueue(p);
            Water[p.first][p.second] |= P;
            
            p = make_pair(i,N-1);
            AddtoQueue(p);
            Water[p.first][p.second] |= A;
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        while(!Q.empty()){
            pair<int,int> p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            for(int k = 0 ; k < 4 ; ++k){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < M && ny >= 0 && ny < N && matrix[nx][ny] >= matrix[x][y]){
                    int targetS = Water[nx][ny] | Water[x][y];
                    if(targetS != Water[nx][ny]){
                        Water[nx][ny] = targetS;
                        AddtoQueue(make_pair(nx,ny));
                    }
                }
            }
        }
        vector<pair<int,int>> ret;
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(Water[i][j] == 3){
                    ret.push_back(make_pair(i,j));
                }
            }
        }
        return ret;
    }
    void Test(){
        vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        vector<pair<int,int>> ret = pacificAtlantic(matrix);
        for(auto p : ret){
            printf("(%d,%d)\n",p.first,p.second);
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
