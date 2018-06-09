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

/*
1 2 3
4 5 6
7 8 9

Case1: starting from 1(or 3,9,7):
C1_Rotate1: 1 -> 2 or 3 depending on whether 2 has been used
C1_Rotate2: 1 -> 4 or 7 depending on whether 4 has been used
C1_Cross: 1-> 5 or 9 depending on whether 5 has been used
C1_HalfCross1 : 1 -> 6
C1_HalfCross2 : 1 -> 8

Case2: starting from 2(or 6,8,4):
C2_Next1 = 2 -> 3
C2_Next2 = 2 -> 1
C2_Diag1 = 2 -> 6
C2_Diag2 = 2 -> 4
C2_HalfCross1 : 2 -> 9
C2_HalfCross2 : 2 -> 7
C2_Cross : 2 -> 5 or 8 depending on whether 5 has been used

Case3: starting from 5:
C3_Next : 5 -> 1,2,3,4,6,7,8,9
*/

class Solution {
    vector<int> S;
    vector<int> RoundID,RoundV;
    int Rotate(int start, int k){
        return start != 5 ? RoundV[((RoundID[start] + 8 + k)%8)]
                          : 0; 
    }
    bool Check(int state, int k){
        return state & S[k];
    }
    vector<int> C1_Next(int state, int start){
        if(start % 2 == 0 || start == 5) return {};
        vector<int> ret;
        int C1_Rotate1 = Rotate(start,Check(state,Rotate(start,1)) ? 2 : 1);
        int C1_Rotate2 = Rotate(start,Check(state,Rotate(start,-1)) ? -2 : -1);
        int C1_Cross = Check(state,5) ? Rotate(start, 4) : 5;
        int C1_HalfCross1 = Rotate(start,3);
        int C1_HalfCross2 = Rotate(start,-3);
        return {C1_Rotate1,C1_Rotate2,C1_Cross,C1_HalfCross1,C1_HalfCross2};
    }
    vector<int> C2_Next(int state, int start){
        if(start % 2 == 1) return {};
        int C2_Next1 = Rotate(start, 1);
        int C2_Next2 = Rotate(start, -1);
        int C2_Diag1 = Rotate(start, 2);
        int C2_Diag2 = Rotate(start, -2);
        int C2_HalfCross1 = Rotate(start, 3);
        int C2_HalfCross2 = Rotate(start, -3);
        int C2_Cross = Check(state,5) ? Rotate(start,4) : 5;
        return {C2_Next1,C2_Next2,C2_Diag1,C2_Diag2,C2_HalfCross1,C2_HalfCross2,C2_Cross};
    }
    vector<int> C3_Next(int state, int start){
        if(start != 5) return {};
        return {1,2,3,4,6,7,8,9};
    }
    vector<int> Next(int state, int start){
        vector<int> ret, tmp;
        switch(start){
            case 1:case 3:case 7:case 9:
                tmp = C1_Next(state,start);
                break;
            case 2:case 4:case 6:case 8:
                tmp = C2_Next(state,start);
                break;
            case 5:
                tmp = C3_Next(state,start);
                break;
            default:
                printf("Error in Next()\n");
        }
        for(auto x:tmp){
            if(!Check(state,x))
                ret.push_back(x);
        }
        return ret;
    }
    void F(int &ANS, int state, int end, int k){
        if(k <= 0) return;
        if(k == 1){
            ++ANS;
            return;
        }
        vector<int> start = Next(state,end);
        for(auto x:start){
            F(ANS,state | S[x],x,k-1);
        }
    }
public:
    Solution(){
        /*
        start      RoundID
        1 2 3       0 1 2
        4 5 6  ->   7 x 3
        7 8 9       6 5 4
        */
        RoundID = vector<int>({-1,0,1,2,7,-1,3,6,5,4});
        RoundV = vector<int>({1,2,3,6,9,8,7,4});
        S = vector<int>({1,2,4,8,16,32,64,128,256,512});
    }
    int numberOfPatterns(int m, int n) {
        int ANS = 0;
        for(int k = m ; k <= n ; ++k){
            for(int start = 1 ; start <= 9 ; ++start){
                F(ANS,S[start],start,k);
            }
        }
        return ANS;
    }
    void Test(){
        printf("%d\n",numberOfPatterns(1,2));
        //ShowNext(S[2],1);
    }
    void ShowNext(int state,int start){
        printf("Next(%d,%d)\n",state,start);
        vector<int> v = Next(state,start);
        for(auto x : v){
            printf("%d ",x);
        }
        printf("\n");
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
