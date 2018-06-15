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

class Solution {
    map<char,int> M;
    int D;//Number of different letters
    int K;//Number of different letters that 
    //          appears no less then k times
    void Clear(){
        M.clear();
        D = K = 0;
    }
    void Add(char ch, int k){
        int count = ++M[ch];
        D += count == 1;
        K += count == k;
    }
    void Remove(char ch, int k){
        int count = --M[ch];
        D -= count == 0;
        K -= count == k - 1;
    }
    int dkSubstring(string &s,int N, int d,int k){
        //max length of a substring that
        //has d characters that each appear
        //no less than k times
        //Note: without d, it is hard to use two pointers.
        Clear();
        int L = 0, R = 0, MaxLen = 0;
        while(true){
            if(D < d){//R++ if less than d distinct chars
                if(R < N)
                    Add(s[R++],k);
                else
                    break;
            }
            else if(D > d){//L++ if more than d distinct chars
                Remove(s[L++],k);
                //--R to make sure D <= d
                Remove(s[--R],k);
                continue;
            }
            else{
                if(K == D){
                    MaxLen = max(MaxLen,R - L);
                }
                //R++ to find longer strings
                if(R < N)
                    Add(s[R++],k);
                else
                    break;
            }
        }
        return MaxLen;
    }
public:
    int longestSubstring(string s, int k) {
        int N = s.length(), MaxLen = 0;
        if(k == 0)
            return N;
        for(int d = 1 ; d <= 26 ; ++d){
            MaxLen = max(MaxLen,dkSubstring(s,N,d,k));
        }
        return MaxLen;
    }
    void Test(){
        printf("%d\n",longestSubstring("ababbc",2));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
