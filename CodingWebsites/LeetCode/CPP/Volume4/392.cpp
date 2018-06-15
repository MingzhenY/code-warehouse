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
    bool isSubsequence(string s, string t) {
        int lt = t.length(), it = 0;
        for(auto ch : s){
            while(it < lt && t[it] != ch)
                it++;
            if(it == lt)
                return false;
            ++it;
        }
        return true;
    }
    void Test(){
        printf("%d\n",isSubsequence("1347","al1fjd3kslf4jad7sk"));
        printf("%d\n",isSubsequence("13479","al1fjd3kslf4jad7sk"));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
