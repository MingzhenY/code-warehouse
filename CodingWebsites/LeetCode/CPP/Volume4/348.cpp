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

class TicTacToe {
    int N;
    map<int,int> Row[2],Col[2];
    int Diag[2][2];
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        memset(Diag,0,sizeof(Diag));
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        player -= 1;
        if(row == col){
            if(N == ++Diag[player][0])
                return player + 1;
        }
        if(row + col == N - 1){
            if(N == ++Diag[player][1])
                return player + 1;
        }
        if(N == ++Row[player][row])
            return player + 1;
        if(N == ++Col[player][col])
            return player + 1;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
