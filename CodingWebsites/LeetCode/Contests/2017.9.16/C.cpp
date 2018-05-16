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
public:
    bool checkValidString(string s) {
        int N = s.length();
        if(!N) return true;
        vector<vector<bool>> DP(N,vector<bool>(N,false));
        for(int j = 0 ; j < N ; ++j){
            for(int i = j ; i >=0 ; --i){
                //[i,j]
                if(i == j){
                    DP[i][j] = s[i] == '*';
                }
                else if(i + 1 == j){
                    DP[i][j] =
                    (s[i] == '*' && s[j] != '(') ||
                    (s[i] != ')' && s[j] == '*') ||
                    (s[i] == '(' && s[j] == ')');
                    
                }
                else {
                    bool Outside =
                    (s[i] == '*' && s[j] != '(') ||
                    (s[i] != ')' && s[j] == '*') ||
                    (s[i] == '(' && s[j] == ')') ;
                    
                    DP[i][j] = DP[i][j] || (Outside && DP[i + 1][j - 1]);
                    DP[i][j] = DP[i][j] || (s[i] == '*' && DP[i + 1][j]);
                    DP[i][j] = DP[i][j] || (s[j] == '*' && DP[i][j - 1]);
                    
                    for(int k = i ; k < j ; ++k){
                        //split [i,k],[k+1,j]
                        DP[i][j] = DP[i][j] || (DP[i][k] && DP[k + 1][j]);
                    }
                }
            }
        }
        return DP[0][N - 1];
    }
    void Test(){
        cout<<checkValidString("(*()")<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
