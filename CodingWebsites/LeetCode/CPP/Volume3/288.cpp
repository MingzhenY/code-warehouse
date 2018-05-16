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

class ValidWordAbbr {
    map<string,string> Abbr;
    map<string,int> AbbrCount;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto x:dictionary){
            if(Abbr.count(x)) continue;
            string t = abbr(x);
            Abbr[x] = t;
            ++AbbrCount[t];
        }
    }
    
    bool isUnique(string word) {
        return Abbr.count(word) && AbbrCount(abbr(word)) == 1 ||
               !Abbr.count(word) && AbbrCount(abbr(word)) == 0;
    }
    string abbr(string str){
        int n = str.length();
        return string("") + str[0] + to_string(n - 2) + str[n-1];
    }
};

int main(){
    vector<string> dictionary = {"deer","door","cake","card"};
    ValidWordAbbr A(dictionary);
    
    
	return 0;
}
