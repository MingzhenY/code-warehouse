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
    int maximumSwap(int num) {
        vector<int> D;
        while(num > 0){
            D.push_back(num % 10);
            num /= 10;
        }
        if(!D.size()) D.push_back(0);
        int N = D.size();
        //reverse D
        for(int i = 0 ; i < N/2 ; ++i) swap(D[i],D[N - 1 - i]);
        
        //convert D
        int I = 0;
        while(I + 1 < N && D[I + 1] <= D[I]) ++I;
        //printf("I = %d\n",I);
        if(I + 1 < N){
            int MaxVal = D[I],Maxi = I;
            for(int i = I + 1; i < N ; ++i){
                if(D[i] >= MaxVal){
                    MaxVal = D[i];
                    Maxi = i;
                }
            }
            //printf("Maxi = %d\n",Maxi);
            for(int i = 0 ; i <= I ; ++i){
                if(D[i] < MaxVal){
                    swap(D[i],D[Maxi]);
                    break;
                }
            }
        }
        //reverse D
        for(int i = 0 ; i < N/2 ; ++i) swap(D[i],D[N - 1 - i]);
        
        //record answer
        int ANS = 0;
        for(int i = D.size() - 1 ; i >= 0 ; --i){
            ANS = ANS * 10 + D[i];
        }
        
        return ANS;
    }
    void Test(){
        cout<<maximumSwap(99901)<<endl;
        
        
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
