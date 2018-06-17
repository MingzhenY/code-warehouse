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
    map<char,int> M;
    vector<string> Numbers;
    void remove(int n,int k){
        for(auto ch : Numbers[n]){
            M[ch] -= k;
        }
    }
public:
    string originalDigits(string s) {
        Numbers = vector<string>({"zero","one","two","three","four",
                            "five","six","seven","eight","nine"});
        for(auto ch : s)
            M[ch]++;
        int C[10];
        remove(8,C[8]=M['g']);
        remove(6,C[6]=M['x']);
        remove(7,C[7]=M['s']);
        remove(5,C[5]=M['v']);
        remove(9,C[9]=M['i']);
        remove(4,C[4]=M['u']);
        remove(3,C[3]=M['h']);
        remove(2,C[2]=M['w']);
        remove(1,C[1]=M['n']);
        remove(0,C[0]=M['o']);
        string ret;
        for(int i = 0 ; i <= 9 ; ++i){
            for(int j = 0 ; j < C[i] ; ++j){
                ret+=to_string(i);
            }
        }
        return ret;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
