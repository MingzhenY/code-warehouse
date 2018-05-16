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
    int trap(vector<int>& height) {
        vector<int> L,R,Sum;
        StepOne_Peak(height,L,R);
        StepTwo_Sum(height,Sum);
        return StepThree_Calculate(height,Sum,L,R);
    }
    void StepOne_Peak(vector<int> & height,vector<int> &L,vector<int> &R){
        int N = height.size(), PreH;
        
        L.clear();
        PreH = 0;
        //printf("L:");
        for(int i = 0 ; i < N ; ++i){
            if(height[i] >= PreH){
                PreH = height[i];
                L.push_back(i);
                //printf("%d ",i);
            }
        }
        //printf("\n");
        
        R.clear();
        PreH = 0;
        //printf("R:");
        for(int i = N - 1 ; i >= 0 ; --i){
            if(height[i] > PreH){
                PreH = height[i];
                R.push_back(i);
                //printf("%d ",i);
            }
        }
        //printf("\n");
    }
    void StepTwo_Sum(vector<int>& height,vector<int>& Sum){
        int N = height.size();
        Sum.resize(N + 1);
        Sum[0] = 0;
        for(int i = 1 ; i <= N ; ++i){
            Sum[i] = Sum[i - 1] + height[i - 1];
        }
    }
    int StepThree_Calculate(vector<int>& height,vector<int>& Sum,vector<int>& L,vector<int>& R){
        int ANS = 0, LN = L.size(), RN = R.size();
        //Left Part
        for(int i = 1 ; i < LN ; ++i){
            ANS += height[L[i - 1]] * (L[i] - L[i - 1]) - (Sum[L[i]] - Sum[L[i - 1]]);
            //printf("%d\n",height[L[i - 1]] * (L[i] - L[i - 1]) - (Sum[L[i]] - Sum[L[i - 1]]));
        }
        //Right Part
        for(int i = 1 ; i < RN ; ++i){
            ANS += height[R[i - 1]] * (R[i - 1] - R[i]) - (Sum[R[i - 1] + 1] - Sum[R[i] + 1]);
            //printf("%d\n",height[R[i - 1]] * (R[i - 1] - R[i]) - (Sum[R[i - 1] + 1] - Sum[R[i] + 1]));
        }
        return ANS;
    }
    void Test(){
        int A[] = {1,5,2,1,2,1,5,2,4,1};
        //int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        vector<int> height(A,A+sizeof(A)/sizeof(A[0]));
        
        cout<<trap(height)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
