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
    #define K 137
    struct INFO{
        int L;//string length
        int LH,RH;//Left hash and right hash
    };
    int pow(int a, int k){
        int ANS = 1;
        while(k){
            if(k & 1) ANS *= a;
            a *= a;
            k >>= 1;
        }
        return ANS;
    }
    int getLH(string &s){
        int LH = 0, L = s.length();
        for(int i = 0 ; i < L ; ++i)
            LH = LH * 137 + s[i];
        return LH;
    }
    int getRH(string &s){
        int RH = 0, L = s.length();
        for(int i = L - 1 ; i >= 0 ; --i)
            RH = RH * 137 + s[i];
        return RH;
    }
    bool isP(INFO A,INFO B){
        int RH = A.RH + B.RH * pow(K,A.L);
        int LH = A.LH * pow(K,B.L) + B.LH;
        return LH == RH;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        vector<INFO> V;
        for(auto x:words){
            INFO i;
            i.L = x.length();
            i.LH = getLH(x);
            i.RH = getRH(x);
            V.push_back(i);
        }
        int N = V.size();
        for(int i = 0 ; i < N ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(i != j && isP(V[i],V[j])){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
    void Test(){
        vector<string> words = {"abcd","dcba","lls","s","sssll"};
        vector<vector<int>> ANS = palindromePairs(words);
        for(auto pair:ANS){
            printf("%d %d\n",pair[0],pair[1]);
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
