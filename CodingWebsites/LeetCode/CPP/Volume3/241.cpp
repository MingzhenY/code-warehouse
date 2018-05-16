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
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        //scan input
        for(int i = 0 ; i < input.length() ;){
            if(input[i] >= '0' && input [i] <= '9'){
                int j = i;
                while(input[j] >= '0' && input[j] <= '9') ++j;
                //[i,j) is the number
                int v = 0;
                for(int k = i ; k < j ; ++k)
                    v = v * 10 + input[k] - '0';
                nums.push_back(v);
                i = j;
            }
            else{
                ops.push_back(input[i++]);
            }
            
        }
        //calculate
        int N = nums.size();
        vector<vector<vector<int>>> D(N,vector<vector<int>>(N,vector<int>()));
        vector<int> EmptyVector;
        //D[i][j] = possible outcomes from nums[i] to nums[j] inclusive
        for(int i = N - 1 ; i >= 0 ; --i){
            for(int j = i ; j < N ; ++j){
                //numbers[i..j]
                if(i == j){
                    D[i][j].push_back(nums[i]);
                }
                else{
                    for(int k = i ; k < j ; ++k){
                        vector<int> &L = D[i][k];
                        vector<int> &R = D[k+1][j];
                        for(int Li = 0 ; Li < L.size() ; ++Li){
                            for(int Ri = 0 ; Ri < R.size() ; ++Ri){
                                D[i][j].push_back(F(L[Li],R[Ri],ops[k]));
                            }
                        }
                    }
                }
            }
        }
        return D[0][N-1];
    }
    int F(int A,int B,char op){
        switch(op){
            case '+':return A+B;
            case '-':return A-B;
            case '*':return A*B;
        }
        return 0;
    }
    void Test(){
        vector<int> ret = diffWaysToCompute("2*3-4*5");
        for(auto x:ret){
            cout<<x<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
