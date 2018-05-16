#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = strs[0];
        for(int i = 1 ; i < strs.size() ; ++i){
            int match = 1;
            for(int j = 0 ; j < min(prefix.length(),strs[i].length()) ; ++j){
                if(strs[i][j] != prefix[j]){
                    prefix = prefix.substr(0,j);
                    match = 0;
                }
                
            }
            if(strs[i].length() < prefix.length()){
                prefix = prefix.substr(0,strs[i].length());
            }
        }
        return prefix;
    }
    void Test(){
        vector<string> S;
        S.push_back("abab");
        S.push_back("aba");
        S.push_back("");
        cout<<longestCommonPrefix(S)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
