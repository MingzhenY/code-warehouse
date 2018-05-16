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
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int Code = 0, n = s.length();
        map<int,int> M;
        for(int i = 0 ; i < n ; i++){
            int CntCode = s[i] == 'A' ? 0 :
                          s[i] == 'G' ? 1 :
                          s[i] == 'C' ? 2 :
                          s[i] == 'T' ? 3 : 0;
            Code = ((Code << 2) | CntCode ) & 1048575;
            if(i >= 9){
                M[Code]++;
                //cout<<i<<":"<<Decode(Code)<<endl;
            }
        }
        vector<string> S;
        for(auto x:M){
            if(x.second > 1){
                S.push_back(Decode(x.first));
            }
        }
        return S;
    }
    string Decode(int x){
        string str(10,'0');
        for(int i = 0 ; i < 10 ; i++){
            switch(x & 3){
                case 0:str[9 - i] = 'A';break;
                case 1:str[9 - i] = 'G';break;
                case 2:str[9 - i] = 'C';break;
                case 3:str[9 - i] = 'T';break;
            }
            x >>= 2;
        }
        return str;
    }
    void Test(){
        vector<string> S = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
        for(auto str : S){
            cout<<str<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
