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
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int i = 0 ; i < N / 2 ; ++i){
            for(int j = 0 ; j < N / 2 ; ++j){
                rotate4(matrix,N,i,j);
            }
        }
        if(N & 1){
            for(int i = 0 ; i < N / 2 ; ++i){
                rotate4(matrix,N,i,N / 2);
            }
        }
    }
    void rotate4(vector<vector<int>>& matrix,int N,int i,int j){
        //(i,j)->(j, N - i - 1)->(N - i - 1, N - j - 1)->(N - j - 1,i)->(i,j)
        int t = matrix[i][j];
        matrix[i][j] = matrix[N - j - 1][i];
        matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
        matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
        matrix[j][N - i - 1] = t;
    }
    void Test(){/*
        int n = 4;
        int M[4][4]={
            {5,1,9,11},
            {2,4,8,10},
            {13,3,6,7},
            {15,14,12,16}
        };*/
        int n = 3;
        int M[3][3]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
        
        
        
        vector<vector<int>> V;
        for(int i = 0 ; i < n ; ++i){
            vector<int> temp(M[i],M[i]+sizeof(M[i])/sizeof(int));
            V.push_back(temp);
        }
        rotate(V);
        for(auto line:V){
            for(auto x:line){
                printf("%d ",x);
            }
            printf("\n");
        }
    }
    
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
