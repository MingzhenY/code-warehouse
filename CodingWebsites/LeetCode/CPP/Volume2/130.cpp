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
using namespace std;

class Solution {
private:
    struct P{
        int x,y;
        P(){}
        P(int x,int y):x(x),y(y){}
    };
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(!n) return;
        int m = board[0].size();
        //Change 'O's around the edges to 'V'
        queue<P> Q;
        for(int i = 0 ; i < n ; ++i){
            if(board[i][0] == 'O') Q.push(P(i,0));
            if(board[i][m-1] == 'O') Q.push(P(i,m-1));
        }
        for(int i = 0 ; i < m ; ++i){
            if(board[0][i] == 'O') Q.push(P(0,i));
            if(board[n-1][i] == 'O') Q.push(P(n-1,i));
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!Q.empty()){
            P cnt = Q.front();Q.pop();
            board[cnt.x][cnt.y] = 'V';
            for(int i = 0 ; i < 4 ; ++i){
                int nx = cnt.x + dx[i], ny = cnt.y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(board[nx][ny] == 'O'){
                        Q.push(P(nx,ny));
                    }
                }
            }
        }
        //Change remaining 'O's to 'X'
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        //Change 'V's to 'O'
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(board[i][j] == 'V') board[i][j] = 'O';
            }
        }

    }
    void Show(string msg,vector<vector<char>> board){
        cout<<msg<<":"<<endl;
        for(auto x : board){
            for(auto c: x){
                cout<<c;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void Test(){
        vector<vector<char>> board;
        string str[] = {"XOXOXO","OXOXOX","XOXOXO","OXOXOX"};
        for(int i = 0 ; i < 4 ; ++i){
            board.push_back(vector<char>());
            for(int j = 0 ; j < 6 ; ++j){
                board[i].push_back(str[i][j]);
            }
        }
        Show("Before",board);
        solve(board);
        Show("After",board);
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
