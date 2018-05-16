#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.length(), nt = t.length();
        if (ns == nt) {
            int Diff = 0;
            for(int i = 0 ; i < ns ; i++) Diff += s[i] != t[i];
            return Diff == 1;
        }else if(ns == nt + 1){
            int L = 0, R = ns - 1;
            while(L < nt){
                if(s[L] == t[L]) L++;
                else break;
            }
            while(R > L){
                if(s[R] == t[R - 1]) R--;
                else break;
            }
            return L == R;
        }else if(ns == nt - 1){
            int L = 0, R = nt - 1;
            while(L < nt){
                if(s[L] == t[L]) L++;
                else break;
            }
            while(R > L){
                if(s[R - 1] == t[R]) R--;
                else break;
            }
            return L == R;
        }
        return false;
    }
    void Test(){
        cout<<"True tests"<<endl;
        cout<<isOneEditDistance("abcde","abde")<<endl;
        cout<<isOneEditDistance("abcde","abkde")<<endl;
        cout<<isOneEditDistance("abcde","abckde")<<endl;
        cout<<"False tests"<<endl;
        cout<<isOneEditDistance("abcde","abcde")<<endl;
        cout<<isOneEditDistance("abcde","ace")<<endl;
        cout<<isOneEditDistance("abcde","abddc")<<endl;
        cout<<isOneEditDistance("abcde","abcdege")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
