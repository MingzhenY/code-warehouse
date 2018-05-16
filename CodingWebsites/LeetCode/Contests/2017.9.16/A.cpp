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
#define Mod 1999999999  //137 * 525547445 mod 1999999999 = 1
#define LL unsigned long long
public:
    bool validPalindrome(string s) {
        int N = s.length();
        vector<LL> MarkL(N,0),MarkR(N,0);
        for(int i = 0 ; i < N ; ++i){
            if(i) MarkL[i] = (MarkL[i - 1] * 137 + s[i]) % Mod ;
            else MarkL[i] = s[i];
        }
        for(int i = N - 1 ; i >= 0 ; --i){
            if(i == N - 1) MarkR[i] = s[i];
            else MarkR[i] = (MarkR[i + 1] * 137 + s[i]) % Mod;
        }
        
        
        for(int i = 0 ; i < N ; ++i){
            //skip i
            //[0,i) + [i + 1,N)
            //L = left + right * 525547445
            LL L = (getL(MarkL,0,i) * Pow(137,N - i - 1) + getL(MarkL,i + 1,N) ) % Mod;
            //R = right + left * 525547445
            LL R = (getR(MarkR,0,i) + getR(MarkR,i + 1,N) * Pow(137,i)) % Mod;
            if(L == R) return true;
        }
        
        return MarkL[N - 1] == MarkR[0];
    }
    LL getL(vector<LL> &MarkL,int L,int R){//[L,R)
        if(L >= R) return 0;
        LL Big = MarkL[R - 1];
        LL Small = L > 0 ? MarkL[L - 1] : 0;
        Small = Small * Pow(137,R - L) % Mod;
        return (Big + Mod - Small) % Mod;
    }
    LL getR(vector<LL> &MarkR,int L,int R){//[L,R)
        if(L >= R) return 0;
        LL Big = MarkR[L];
        LL Small = R < MarkR.size() ? MarkR[R] : 0;
        Small = Small * Pow(137,R - L) % Mod;
        return (Big + Mod - Small) % Mod;
    }
    LL Pow(LL a,LL k){
        LL ANS = 1;
        while(k){
            if(k & 1) ANS = ANS * a % Mod;
            a = a * a % Mod;
            k >>= 1;
        }
        return ANS;
    }
    void Test(){
        cout<<validPalindrome("aba")<<endl;
        cout<<validPalindrome("abca")<<endl;
        cout<<validPalindrome("aabb")<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
