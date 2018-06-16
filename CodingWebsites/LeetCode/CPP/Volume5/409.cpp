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
    int longestPalindrome(string s) {
        map<char,int> M;
        for(auto ch:s){
            M[ch]++;
        }
        int Extra = 0, Len = 0;
        for(auto x : M){
            Len += x.second / 2 * 2;
            Extra += x.second % 2;
        }
        return Len + (Extra > 0);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
