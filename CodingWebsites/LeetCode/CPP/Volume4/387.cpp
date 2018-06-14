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
    int firstUniqChar(string s) {
        map<char,int> M;
        for(auto ch:s){
            M[ch]++;
        }
        for(int i = 0 ; i < s.length() ; ++i){
            if(M[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
