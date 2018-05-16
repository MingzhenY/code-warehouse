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
    bool canPermutePalindrome(string s) {
        sort(s.begin(),s.end());
        int n = s.length(), CountSingle = 0;
        for(int i = 0 ; i < n ; ++i){
            if(i + 1 < n && s[i+1]==s[i]){
                //found a pair, advance
                ++i;
            }
            else ++CountSingle;
        }
        return CountSingle <= 1;
    }
    void Test(){
        cout<<canPermutePalindrome("aab")<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
