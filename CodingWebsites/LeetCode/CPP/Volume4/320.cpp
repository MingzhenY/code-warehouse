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
    vector<string> generateAbbreviations(string word) {
        int L = word.length();
        if(L > 20) return {};
        int N = (1 << L);
        vector<string> ret;
        for(int i = 0 ; i < N ; ++i){
            string rs;
            int Count = 0;
            for(int j = 0, X = i ; j <= L ; ++j, X >>= 1){
                char ch = j < L && (X & 1) ? word[j] : '_';
                if(j == L || ch != '_'){
                    if(Count){
                        rs += to_string(Count);
                        Count =  0;
                    }
                    rs += word[j];
                }
                else Count++;

            }
            ret.push_back(rs);
        }
        return ret;
    }
    void Test(){
        vector<string> ans = generateAbbreviations("word");
        for(auto s : ans){
            cout<<s<<endl;
        }
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
