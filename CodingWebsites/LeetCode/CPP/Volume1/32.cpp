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
    int longestValidParentheses(string s) {
        //Step One: change '(' into 1 and ')' into -1, Sum up
        int N = s.length();
        vector<int> Sum(N + 1,0);
        for(int i = 1 ; i <= N ; ++i) Sum[i] = Sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        
        //Step Two: search
        int ANS = 0, StartH = 0, StartI = 0;
        //Search from left
        for(int i = 1 ; i <= N ; ++i){
            if(Sum[i] == StartH){
                ANS = max(ANS,i - StartI);
            }
            else if(Sum[i] < StartH){
                StartH = Sum[i];
                StartI = i;
            }
        }
        //Search from right
        StartH = Sum[N], StartI = N;
        for(int i = N - 1 ; i >= 0 ; --i){
            if(Sum[i] == StartH){
                ANS = max(ANS,StartI - i);
            }
            else if(Sum[i] < StartH){
                StartH = Sum[i];
                StartI = i;
            }
        }
        return ANS;
    }
    void Test(){
        cout<<longestValidParentheses("))()((())()))))")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
