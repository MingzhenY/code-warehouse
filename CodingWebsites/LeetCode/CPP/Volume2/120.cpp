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
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int M = triangle.size();
        if(!M) return 0;
        for(int i = 1 ; i < M ; ++i){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for(int j = 1 ; j < i ; ++j){
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        int Min = triangle[M-1][0];
        for(int j = 1 ; j < M ; ++j){
            Min = min(Min,triangle[M-1][j]);
        }
        return Min;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
