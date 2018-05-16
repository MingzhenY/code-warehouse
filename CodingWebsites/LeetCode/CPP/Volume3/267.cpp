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
public:
    vector<string> generatePalindromes(string s) {
        int Single = -1;
        if(!canPermutePalindrome(s,Single)) return {};
        string mid,rest;
        if(~Single){
            mid = s[Single];
            rest = s.substr(0,Single) + s.substr(Single + 1, s.length() - Single - 1);
        }
        else{
            mid = "";
            rest = s;
        }
        int n = rest.length();
        for(int i = 0 ; i < n / 2 ; ++i) rest[i] = rest[i * 2 + 1];
        rest = rest.substr(0,n/2);
        n /= 2;
        printf("mid = %s, rest = %s\n",mid.c_str(),rest.c_str());
        
        //permutate rest
        vector<string> V = P(rest);
        int Vn = V.size();
        for(int i = 0 ; i < Vn ; ++i){
            string C = V[i] + mid;
            for(int j = V[i].length() - 1 ; j >= 0 ; --j) C += V[i][j];
            V[i] = C;
        }
        return V;
    }
    vector<string> P(string str){
        int d[128] = {};
        for(auto x:str) ++d[x];
        vector<string> ret;
        string temp;
        P2(ret,temp,d,str.length());
        return ret;
    }
    void P2(vector<string> &ret,string &str,int *d,int len){
        if(len == 0){
            ret.push_back(str);
        }
        for(int i = 0 ; i < 128 ; ++i){
            if(d[i]){
                str += char(i);
                --d[i];
                P2(ret,str,d,len-1);
                ++d[i];
                str = str.substr(0,str.length() - 1);
            }
        }
    }
    bool canPermutePalindrome(string &s,int &Single) {
        sort(s.begin(),s.end());
        int n = s.length(), CountSingle = 0;
        for(int i = 0 ; i < n ; ++i){
            if(i + 1 < n && s[i+1]==s[i]){
                //found a pair, advance
                ++i;
            }
            else ++CountSingle, Single = i;
        }
        return CountSingle <= 1;
    }
    void Test(){
        vector<string> ret = generatePalindromes("aba");
        for(auto x:ret){
            cout<<x<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
