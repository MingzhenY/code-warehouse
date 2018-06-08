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
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
    void Test(){
        string s = reverseString("hello");
        cout<<s<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
