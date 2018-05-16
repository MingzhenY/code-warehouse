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
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string> > ANS;
        if(!n) return ANS;
        Cut(s,vector<int>(),0,n,ANS);
        return ANS;
    }
    void Cut(string &s,vector<int> VCut,int L,int R,vector<vector<string> > &ANS){
        if(L == R){
            int n = VCut.size();
            if(!n) return;
            vector<string> V;
            V.push_back(s.substr(0,VCut[0]));
            for(int i = 1 ; i < n ; ++i){
                V.push_back(s.substr(VCut[i - 1],VCut[i] - VCut[i - 1]));
            }
            ANS.push_back(V);
            return;
        }
        //[L,R) find first cut
        for(int i = L + 1; i <= R ; ++i){
            if(check(s,L,i)){
                VCut.push_back(i);
                Cut(s,VCut,i,R,ANS);
                VCut.erase(VCut.begin() + VCut.size() - 1);
            }
        }
    }
    bool check(string s,int L,int R){//[L,R)
        long long VL = 0 , VR = 0;
        for(int i = L, j = R - 1 ; i < R ; ++i, --j){
            VL = VL * 137 + s[i];
            VR = VR * 137 + s[j];
        }
        return VL == VR;
    }
    void Test(){
        string str = "aabaabcdcba";
        vector<vector<string> > ANS = partition(str);
        for(auto line : ANS){
            for(auto x : line){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
