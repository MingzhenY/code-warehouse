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
    bool validWordSquare(vector<string>& words) {
        int N = words.size();
        if(!N) return true;
        int L = words[0].size();
        if(N != L) return false;
        for(int j = 0 ; j < L ; ++j){
            string col;
            for(int i = 0 ; i < N ; ++i){
                //words[i][j]
                if(j < words[i].length())
                    col += words[i][j];
            }
            if(col != words[j]) return false;
        }
        return true;
    }
    void Test(){
        vector<string> words = {"abcd","bnrt","crm","dt"};
        printf("%d\n",validWordSquare(words));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
