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
    string Zeroes(int k){
        string str(k,'0');
        return str;
    }
public:
    string addStrings(string num1, string num2) {
        int L1 = num1.size(), L2 = num2.size();
        int L = max(L1,L2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        num1 += Zeroes(L - L1);
        num2 += Zeroes(L - L2);
        int D = 0;
        string ret;
        for(int i = 0 ; i < L ; ++i){
            int V = num1[i] + num2[i] - '0' - '0' + D;
            D = V / 10;
            V %= 10;
            ret += char(V + '0');
        }
        if(D)
            ret += char('1');
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
