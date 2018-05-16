#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int L, R, n = s.length(), X;
        if(!n) return s;
        L = R = 0;
        X = -1;
        for(int i = 0, p137 = 1 ; i < n ; i++, p137 *= 137){
            //Update L and R
            L = L + s[i] * p137;
            R = R * 137 + s[i];
            //Update X if find a palindrome
            if(L == R) X = i;
        }
        //[0,X] is now the longest palindrome starting from begining
        string ANS;
        for(int i = n - 1 ; i > X ; i--) ANS += s[i];
        ANS += s;
        return ANS;
        
    }
    void Test(){
        cout<<shortestPalindrome("aacecaaa")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
