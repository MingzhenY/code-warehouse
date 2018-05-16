#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        int ANS = 0 , L , R;
        
        for(int I = 0 ; I < N ; ++I){
            int T = Test(s,N,I,I);
            if(T > ANS){
                ANS = T;
                L = I - T/2;
            }
            
        }
        for(int I = 1 ; I < N ; ++I){
            int T = Test(s,N,I - 1,I);
            if(T > ANS){
                ANS = T;
                L = I - T/2;
            }
        }
        return s.substr(L,ANS);
    }
    int Test(string &str,int N,int L,int R){
        int Length = -(L == R);
        while(1){
            if(str[L] == str[R]){
                Length += 2;
                --L;
                ++R;
                if(L < 0 || R >= N) return Length;
            }
            else return Length;
        }
        return 0;
    }
    void Test(){
        string str;
        while(cin>>str){
            cout<<longestPalindrome(str)<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
