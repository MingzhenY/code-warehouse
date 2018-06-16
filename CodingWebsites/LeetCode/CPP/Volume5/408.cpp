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
    bool validWordAbbreviation(string word, string abbr) {
        int WL = word.length();
        int WI = 0, i;
        int L = abbr.length();
        for(i = 0 ; i < L && WI < WL ;){
            if(isalpha(abbr[i])){
                if(word[WI] != abbr[i])
                    return false;
                WI++;
                i++;
            }
            else{
                int t = i;
                while(t < L && abbr[t] >= '0' && abbr[t] <= '9')
                    t++;
                //number is [i,t)
                if(abbr[i] == '0') return false;
                int skip = stoi(abbr.substr(i,t-i));
                WI += skip;
                i = t;
                //printf("skip = %d\n",skip);
            }
        }
        //printf("WI = %d, WL = %d\n",WI,WL);
        return WI == WL && i == L;
    }
    void Test(){
        printf("%d\n",validWordAbbreviation("internationalization","i18n"));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
