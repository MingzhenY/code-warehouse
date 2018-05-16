#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool visit[3][9][9];
        memset(visit,0,sizeof(visit));
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j] == '.') continue;
                
                int I,J,K = board[i][j] - '1';
                I = 0 , J = i;
                if(visit[I][J][K]) return false;
                else visit[I][J][K] = true;
                
                I = 1 , J = j;
                if(visit[I][J][K]) return false;
                else visit[I][J][K] = true;
                
                I = 2 , J = i / 3 * 3 + j / 3;
                if(visit[I][J][K]) return false;
                else visit[I][J][K] = true;
            }
        }
        return true;
    }
    void Test(){
        char board[9][10] = {"....4.9..","..21..3..",".........","........3","...2.....",".....7...","...61....","..9......",".......9."};
        vector<vector<char>> B(9);
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                B[i].push_back(board[i][j]);
            }
        }
        
        for(auto line : B){
            for(auto ch : line){
                cout<<ch;
            }
            cout<<endl;
        }
        cout<<endl;
        
        cout<<isValidSudoku(B)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
