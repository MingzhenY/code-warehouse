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
    int minDistance(string word1, string word2) {
        int N1 = word1.size();
        int N2 = word2.size();
        vector<vector<int>> D(N1 + 1,vector<int>(N2 + 1));
        for(int i = 0 ; i <= N1 ; ++i){
            for(int j = 0 ; j <= N2 ; ++j){
                if(!i || !j) {
                    D[i][j] = max(i,j);
                    continue;
                }
                int DL = D[i - 1][j] + 1;
                int DR = D[i][j - 1] + 1;
                int DD = D[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
                D[i][j] = min(min(DL,DR),DD);
            }
        }
        return D[N1][N2];
    }
    void Test(){
        string word1 = "acfgd";
        string word2 = "abcfgk";
        cout<<minDistance(word1,word2)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
