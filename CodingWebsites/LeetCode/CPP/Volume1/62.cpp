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
    int uniquePaths(int m, int n) {
        vector<vector<int>> D(m,vector<int>(n,0));
        D[m - 1][n - 1] = 1;
        for(int i = m - 1 ; i >= 0 ; --i){
            for(int j = n - 1 ; j >= 0 ; --j){
                D[i][j] += i + 1 < m ? D[i + 1][j] : 0;
                D[i][j] += j + 1 < n ? D[i][j + 1] : 0;
            }
        }
        return D[0][0];
    }
    void Test(){
        cout<<uniquePaths(3,4)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
