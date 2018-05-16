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
private:
    int S[128];
    int T[128];
    int Sn,Tn;
public:
    string minWindow(string s, string t) {
        //record information in t
        setT(t);
        initS();
        if(t == "") return "";
        
        int N = s.length();
        int L = 0 , R = 0;//[L,R)
        int start = 0,end = N + 1;
        while(1){
            if(isValid()){
                //record answer
                if(R - L < end - start){
                    start = L;
                    end = R;
                }
                //increase L
                if(L < N) removeFromS(s[L++]);
                else break;
            }
            else{
                //increase R
                if(R < N) addToS(s[R++]);
                else break;
            }
        }
        return end == N + 1 ? "" : s.substr(start,end - start);
    }
    void setT(string &t){
        memset(T,0,sizeof(T));
        int N = t.length();
        for(int i = 0 ; i < N ; ++i){
            ++T[t[i]];
        }
        Tn = 0;
        for(int i = 0 ; i < 128 ; ++i) Tn += T[i] != 0;
    }
    void initS(){
        memset(S,0,sizeof(S));
        Sn = 0;
    }
    void addToS(char ch){
        Sn += ++S[ch] == T[ch];
    }
    void removeFromS(char ch){
        Sn -= S[ch]-- == T[ch];
    }
    bool isValid(){
        return Sn >= Tn;
    }
    void Test(){
        string S = "ADOBECODEBANC";
        string T = "ABC";
        cout<<minWindow(S,T)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
