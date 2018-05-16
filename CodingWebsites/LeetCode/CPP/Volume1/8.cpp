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
    int myAtoi(string str) {
        int Len = str.length();
        State = 0;
        int L = -1,R = -1 , sign = 0;
        for(int i = 0 ; i < Len ; ++i){
            if(0 == State){
                //Check for - or digit
                if(isDigit(str[i]) || str[i] == '-'){
                    State = 1;
                    if(str[i] != '-') L = i;
                    else sign = 1;
                }
            }
            else if(1 == State){
                //Record Numbers
                if(!isDigit) break;
                if(-1 == L) L = i;
                R = i;
            }
        }
        int ANS = 0;
        if(-1 == L) return 0;
        for(int i = L ; i <= R ; ++i){
            ANS = 10 * ANS + 
        }
    }
    bool isDigit(char i){
        return i >= '0' && i <='9';
    }
    void Test(){
        string str;
        while(cin>>str){
            cout<<myAtoi(str)<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
