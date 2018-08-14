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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,pair<int,int>> V;
        for(int i = 0 ; i < A.size() ; ++i){
            for(int j = 0 ; j < B.size() ; ++j){
                pair<int,int> p = V[A[i]+B[j]];
                p.first += 1;
                V[A[i]+B[j]] = p;
            }
        }
        for(int i = 0 ; i < C.size() ; ++i){
            for(int j = 0 ; j < D.size() ; ++j){
                pair<int,int> p = V[-C[i]-D[j]];
                p.second += 1;
                V[-C[i]-D[j]] = p;
            }
        }
        int ret = 0;
        for(auto p:V){
            ret += p.second.first * p.second.second;
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
