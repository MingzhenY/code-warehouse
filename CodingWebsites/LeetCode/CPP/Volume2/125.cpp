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
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        //Turn lower case into upper case
        for(int i = 0 ; i < n ; ++i){
            if (s[i] >= 'a' && s[i] <= 'z' ){
                s[i] = s[i] - ('a' - 'A');
            }
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            }
            else {s[i] = 0;}
        }
        //Calculate Hash value from both sides
        long long LV = 0,RV = 0;
        for(int i = 0 ; i < n ; ++i){
            int j = n - i - 1;
            if(s[i]){
                LV = LV * 137 + s[i];
            }
            if(s[j]){
                RV = RV * 137 + s[j];
            }
        }
        return LV == RV;
    }
    void Test(){
        cout<<isPalindrome("0P")<<endl;
        
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
