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
    int NS,NP;
    int KP,KPP;
    map<char,int> CountS;
    map<char,int> CountP;
    void Add(char ch){
        int c = ++CountS[ch];
        NS += c == 1;
        KP += c == CountP[ch];
        KPP += c == CountP[ch] + 1;
    }
    void Remove(char ch){
        int c = --CountS[ch];
        NS -= c == 0;
        KP -= c == CountP[ch] - 1;
        KPP -= c == CountP[ch];
    }
    bool isValid(){
        return KP == NP && KPP == 0;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        NP = 0;
        for(auto ch : p){
            NP += !CountP[ch]++;
        }
        NS = KP = KPP = 0;
        int L = 0, R = 0, N = s.length();
        vector<int> ret;
        while(L < N){
            if(isValid()){
                ret.push_back(L);
                Remove(s[L++]);
            }
            else{
                if(KPP > 0){
                    //too much letters, L++, --R
                    Remove(s[L++]);
                    Remove(s[--R]);
                }
                else{
                    //not Enough letters, R++
                    if(R < N)
                        Add(s[R++]);
                    else
                        break;
                }
            }
        }
        return ret;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
