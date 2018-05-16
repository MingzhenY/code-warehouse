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
    int lengthOfLastWord(string s) {
        int N = s.length();
        while(N > 0 && s[N - 1] == ' ') --N;
        int L = -1, Count = 0;
        for(int i = 0 ; i < N ; ++i){
            if(s[i] == ' '){
                L = i;
                Count = 0;
            }
            else ++Count;
        }
        return Count;
    }
    void Test(){
        string str = "hello world ";
        cout<<lengthOfLastWord(str)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
