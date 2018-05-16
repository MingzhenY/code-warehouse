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
    string addBinary(string a, string b) {
        int Na = a.size();
        int Nb = b.size();
        int MaxL = max(Na,Nb) + 1;
        string ANS(MaxL,0);
        for(int i = 0 ; i < Na ; ++i){
            ANS[Na - i - 1] += a[i] - '0';
        }
        for(int i = 0 ; i < Nb ; ++i){
            ANS[Nb - i - 1] += b[i] - '0';
        }
        for(int i = 0 ; i < MaxL - 1 ; ++i){
            if(ANS[i] > 1){
                ANS[i + 1] += ANS[i] / 2;
                ANS[i] %= 2;
            }
        }
        if(MaxL > 0 && ANS[MaxL - 1] == 0) --MaxL;
        string SUM(MaxL,'0');
        for(int i = 0 ; i < MaxL ; ++i){
            if(ANS[i]) SUM[MaxL - i - 1] = '1';
        }
        return SUM;
    }
    void Test(){
        string a = "100";
        string b = "101";
        cout<<addBinary(a,b)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
