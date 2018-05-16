#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


class Solution {
private:
    int Len,M,N;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        Len = word.length();
        if(!Len) return true;
        M = board.size();
        if(!M) return false;
        N = board[0].size();
        if(!N) return false;
        
        bool ANS = false;
        vector<vector<bool>> Vis(M,vector<bool>(N,false));
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(board[i][j] == word[0]){
                    Vis[i][j] = true;
                    ANS = ANS || DFS(board,Vis,word,i,j,1);
                    Vis[i][j] = false;
                }
            }
        }
        return ANS;
    }
    bool DFS(vector<vector<char>>& board,vector<vector<bool>>&Vis,string &word,int x,int y,int n){
        if(n == Len) return true;
        bool ANS = false;
        for(int k = 0 ; k < 4 ; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0 && nx < M && ny >= 0 && ny < N && !Vis[nx][ny] && board[nx][ny] == word[n]){
                Vis[nx][ny] = true;
                ANS = ANS || DFS(board,Vis,word,nx,ny,n+1);
                Vis[nx][ny] = false;
            }
        }
        return ANS;
    }
    void Test(){
        char Board[3][4]={
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
        };
        vector<vector<char>> B;
        for(int i = 0 ; i < 3 ; ++i)
            B.push_back(vector<char>(Board[i],Board[i]+sizeof(Board[i])/sizeof(Board[i][0])));
        cout<<exist(B,"ABCCED")<<endl;
        cout<<exist(B,"SEE")<<endl;
        cout<<exist(B,"ABCB")<<endl;
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
