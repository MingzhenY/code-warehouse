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
    void reverseWords(string &s) {
        int L, R = s.length();
        string s_copy(s);
        s = "";
        int count = 0;
        while(R > 0){
            string w = findLastWord(s_copy,L,R);
            R = L;
            if(w != ""){
                if(count++){
                    s = s + " " + w;
                }
                else{
                    s = w;
                }
            }
        }
    }
    string findLastWord(string &s,int &L,int &R){
        //Find first s[i] != ' ' where i < R
        while(R > 0 && s[R - 1] == ' ') --R;
        //Find first s[L-1] == ' ' where L < R
        L = R;
        while(L > 0 && s[L - 1] != ' ') --L;
        //return word[L,R)
        return s.substr(L,R-L);
    }
    void Test(){
        string str = " Once upon a time ";
        reverseWords(str);
        cout<<"|"<<str<<"|"<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
