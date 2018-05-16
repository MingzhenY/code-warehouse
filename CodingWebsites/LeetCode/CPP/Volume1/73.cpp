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
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(!M) return;
        int N = matrix[0].size();
        int Mark = 137;
        while(1){
            Mark = Mark * 137 + 31;
            bool Found = false;
            for(int i = 0 ; i < M ; ++i){
                for(int j = 0 ; j < N ; ++j){
                    if(matrix[i][j] == Mark){
                        i = M;
                        j = N;
                        Found = true;
                    }
                }
            }
            if(!Found) break;
        }
        
        //Mark the slots that would be turned into zeros later
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(matrix[i][j] == 0){
                    for(int x = 0 ; x < M ; ++x)
                        matrix[x][j] = matrix[x][j] ? Mark : 0;
                    for(int x = 0 ; x < N ; ++x)
                        matrix[i][x] = matrix[i][x] ? Mark : 0;
                }
            }
        }
        
        //turn Marks into zeros
        for(int i = 0 ; i < M ; ++i){
            for(int j = 0 ; j < N ; ++j){
                matrix[i][j] = matrix[i][j] == Mark ? 0 :matrix[i][j];
            }
        }
        
    }
    void Test(){
        int A[5][4]=
        {
            {0,0,0,5},
            {4,3,1,4},
            {0,1,1,4},
            {1,2,1,3},
            {0,0,1,1}
        };
        vector<vector<int>> matrix;
        for(int i = 0 ; i < 5 ; ++i){
            matrix.push_back(vector<int>(A[i],A[i]+sizeof(A[i])/sizeof(A[i][0])));
        }
        setZeroes(matrix);
        for(auto line : matrix){
            for(auto x:line){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
