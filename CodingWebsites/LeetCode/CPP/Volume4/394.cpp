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
S = U | US
U = A | K
A = [a-z]+    (e.g. abc)
K = k[S]      (e.g. 2[abc])
*/

class Solution {
    bool isnumber(char ch){
        return ch >= '0' && ch <= '9';
    }
    string getU(string &s, int L, int &R,int N){
        if(L >= N || s[L] == ']'){
            R = L;
            return "";
        }
        if(isalpha(s[L])){
            // U = A
            R = L;
            while(R < N && isalpha(s[R]))
                ++R;
            return s.substr(L, R - L);
        }
        else{
            // U = k[S]
            R = L;
            while(R < N && isnumber(s[R]))
                ++R;
            int k = stoi(s.substr(L,R-L));
            //printf("k=%d\n",k);
            L = R + 1;
            string S = getS(s,L,R,N);
            ++R;
            
            string ret;
            for(int i = 0 ; i < k ; ++i)
                ret += S;
            return ret;
        }
    }
    string getS(string &s, int L, int &R,int N){
        if(L >= N){
            R = L;
            return "";
        }
        string ret;
        while(true){
            string U = getU(s,L,R,N);
            if(U.length() > 0){
                ret += U;
            }
            else break;
            L = R;
        }
        return ret;
    }
    void F(string &ret,string &s, int L,int &R,int N){
        getS(s,L,R,N);
    }
public:
    string decodeString(string s) {
        int R;
        return getS(s,0,R,s.length());
    }
    void Test(){
        string s = decodeString("2[k3[ab]]");
        cout<<s<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
