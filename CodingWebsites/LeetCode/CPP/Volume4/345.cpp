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
    bool isVowel(char ch){
        return ch == 'a' || ch == 'A' ||
            ch == 'e' || ch == 'E' ||
            ch == 'i' || ch == 'I' ||
            ch == 'o' || ch == 'O' ||
            ch == 'u' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        string vowels;
        int N = s.length();
        for(int i = 0 ; i < N ; ++i)
            if(isVowel(s[i]))
                vowels += s[i],
                s[i] = 0;
        reverse(vowels.begin(),vowels.end());
        auto it = vowels.begin();
        for(int i = 0 ; i < N ; ++i)
            if(s[i] == 0)
                s[i] = *it,
                ++it;
        return s;
    }
    void Test(){
        string s = reverseVowels("hello");
        cout<<s<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
