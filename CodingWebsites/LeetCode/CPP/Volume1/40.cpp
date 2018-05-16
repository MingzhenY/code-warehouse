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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> Counts(candidates.size());
        StepOne(candidates,Counts);
        //Using Stack
        int N = candidates.size() , Top = 0;
        vector<int> Times(N,-1);
        int Sum = 0;
        vector<vector<int>> ANS;
        while(Top >= 0){
            if(N == Top){//1. End of search
                //Record Answers
                if(Sum == target){
                    vector<int> tempANS;
                    for(int i = 0 ; i < Top ; ++i){
                        for(int j = 0 ; j < Times[i] ; ++j){
                            tempANS.push_back(candidates[i]);
                        }
                    }
                    ANS.push_back(tempANS);
                }
                //Reduce
                --Top;
            }
            else {
                //increase number count, update sum
                Sum += ++Times[Top] ? candidates[Top] : 0;
                
                //Advance if possible
                if(Sum <= target && Times[Top] <= Counts[Top]){
                    ++Top;
                }
                else{
                    Sum -= candidates[Top] * Times[Top];
                    Times[Top--] = -1;
                }
            }
        }
        return ANS;
    }
    void StepOne(vector<int> &candidates,vector<int> &Counts){
        int N = candidates.size();
        if(!N) return;
        sort(candidates.begin(), candidates.end());
        int V;
        int C = 0;
        int I = 0;
        for(int i = 0 ; i < N ; ++i){
            if(!C){
                ++C;
                V = candidates[i];
            }
            else{
                ++C;
            }
            if(i + 1 == N || candidates[i] != candidates[i + 1]){
                candidates[I] = V;
                Counts[I] = C;
                C = 0;
                ++I;
            }
        }
        candidates.resize(I);
        Counts.resize(I);
    }
    void Test(){
        int A[] = {10,1,2,7,6,1,5};
        int target = 8;
        
        vector<int> candidates(A,A+sizeof(A)/sizeof(A[0]));
        vector<vector<int>> ANS = combinationSum2(candidates,target);
        
        for(auto line: ANS){
            for(auto x:line){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
