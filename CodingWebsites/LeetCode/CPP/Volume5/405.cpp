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
    string toHex(int num) {
        string ret;
        for(int i = 0 ; i < 8 ; ++i){
            char t = num & 15;
            if(t < 10) t += '0';
            else t += 'a' - 10;
            ret += t;
            num >>= 4;
        }
        reverse(ret.begin(),ret.end());
        while(ret.length() > 1 && ret[0] == '0')
            ret = ret.substr(1);
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
