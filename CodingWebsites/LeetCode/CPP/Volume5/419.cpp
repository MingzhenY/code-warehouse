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
public:
    int countBattleships(vector<vector<char>>& board) {
        int M = board.size();
        if(!M) return 0;
        int N = board[0].size();
        
        int Count = 0;
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                Count += board[i][j] == 'X' &&
                        (i == 0 || board[i-1][j] != 'X') &&
                        (j == 0 || board[i][j-1] != 'X');
            }
        }
        return Count;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
