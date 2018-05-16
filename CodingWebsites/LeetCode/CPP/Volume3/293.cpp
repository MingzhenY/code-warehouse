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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ret;
        int len = s.length();
        for(int i = 1 ; i < len ; ++i){
            if(s[i] == s[i-1] && s[i] == '+'){
                //[0,i-1) + flip[i-1,i+1) + [i+1,len)
                string temp = s.substr(0,i-1) +
                (s[i] == '+' ? "--" : "++") +
                s.substr(i+1,len-i-1);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
