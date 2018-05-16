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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                if(Sum <= target){
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
    void Test(){
        int A[] = {9,6,8,11,5,4};
        int target = 34;
        
        vector<int> candidates(A,A+sizeof(A)/sizeof(A[0]));
        vector<vector<int>> ANS = combinationSum(candidates,target);
        
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
