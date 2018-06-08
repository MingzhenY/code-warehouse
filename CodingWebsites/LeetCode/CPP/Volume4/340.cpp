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
    int D;
    map<int,int> Count;
    void Init(){
        D = 0;
    }
    void Add(char ch){
        D += !Count[ch]++;
    }
    void Remove(char ch){
        D -= !--Count[ch];
    }
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int Len = s.length();
        int L = 0 , R = 0, ANS = 0;//[L,R)
        Init();
        while(true){
            if(D <= k){
                if(R - L > ANS)
                    ANS = R - L;
                if(R < Len) Add(s[R++]);
                else break;
            }
            else{
                Remove(s[L++]);
            }
        }
        return ANS;
    }
    void Test(){
        string s = "eceba";
        int k = 2;
        printf("%d\n",lengthOfLongestSubstringKDistinct(s,k));
        printf("%d\n",lengthOfLongestSubstringKDistinct("a",1));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
