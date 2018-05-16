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
    map<char,char> rotate180;
public:
    Solution(){
        rotate180['0'] = '0';
        rotate180['1'] = '1';
        rotate180['6'] = '9';
        rotate180['8'] = '8';
        rotate180['9'] = '6';
    }
    bool isStrobogrammatic(string num) {
        long long L = 0, R = 0;
        int n = num.size();
        for(int i = 0 , p137 = 1; i < n ; ++i, p137 *= 137){
            L = L + p137 * num[i];
            R = R + p137 * rotate180[num[n - i - 1]];
        }
        return L == R;
    }
    void Test(){
        cout<<isStrobogrammatic("60809")<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
