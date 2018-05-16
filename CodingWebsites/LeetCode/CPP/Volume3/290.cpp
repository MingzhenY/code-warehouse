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
    bool wordPattern(string pattern, string str) {
        map<char,long long> M;
        set<long long> S;
        int len = str.length(), L, R = 0;
        for(int i = 0 ; i < pattern.size() ; ++i, ++R){
            L = R;
            long long H = 0;
            while(R < len && str[R] != ' ') H = H * 137 + str[R++] + 7;
            if(L == R) return false;
            cout<<str.substr(L,R-L)<<endl;
            //[L,R) is the word
            if(M.count(pattern[i])){
                if(H != M[pattern[i]]) return false;
            }
            else{
                //match a new pattern to a new string
                M[pattern[i]] = H;
                if(S.count(H)) return false;
                else S.insert(H);
            }
        }
        return R == len + 1;
    }
    void Test(){
        string pattern = "abba";
        string str = "dog cat cat dog";
        cout<<wordPattern(pattern,str)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
