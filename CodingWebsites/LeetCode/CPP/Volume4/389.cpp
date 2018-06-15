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
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int L = s.length();
        for(int i = 0 ; i < L ; ++i)
            if(s[i] != t[i])
                return t[i];
        return t[L];
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
