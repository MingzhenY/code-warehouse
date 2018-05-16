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
    string getHint(string secret, string guess) {
        int n = secret.length();
        int A,B;
        A = 0;
        map<char,int> S;
        map<char,int> G;
        for(int i = 0 ; i < n ; ++i){
            A += secret[i] == guess[i];
            if(secret[i] != guess[i]) {
                ++S[secret[i]];
                ++G[guess[i]];
            }
        }
        B = 0;
        for(auto x:G){
            B += S.count(x.first) ? min(S[x.first],x.second) : 0;
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
