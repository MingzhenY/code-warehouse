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
    string countAndSay(int n) {
        string A = "1";
        while(--n) A = countAndSayString(A);
        return A;
    }
    string countAndSayString(string str){
        int N = str.length();
        int Count = 0;
        char ch;
        char NextStr[10240];
        NextStr[0] = '\0';
        for(int i = 0 ; i < N ; ++i){
            if(!Count){
                ++Count;
                ch = str[i];
            }
            if(i + 1 == N || str[i + 1] != ch){
                //Record Answer
                char tempStr[1024];
                sprintf(tempStr,"%d%c",Count,ch);
                strcat(NextStr,tempStr);
                
                Count = 0;
            }
            else ++Count;
        }
        return NextStr;
    }
    void Test(){
        string str = "1211";
        cout<<countAndSay(4)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
