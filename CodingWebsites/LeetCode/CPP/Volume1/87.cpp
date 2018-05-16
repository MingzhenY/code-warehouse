#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        //Find the split point
        
        
        
    }
    void Test(){
        cout<<isScramble("rgeat","great")<<endl;//true
        cout<<isScramble("rgtae","great")<<endl;//true
        cout<<isScramble("egtar","great")<<endl;//false
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
