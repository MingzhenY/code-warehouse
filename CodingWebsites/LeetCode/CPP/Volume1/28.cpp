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
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int n = needle.size();
        for(int i = 0 ; i <= N - n ; ++i){
            int MatchCount = 0;
            for(int j = 0 ; j < n ; ++j){
                MatchCount += haystack[i + j] == needle[j];
            }
            if(MatchCount == n) return i;
        }
        return -1;
    }
    void Test(){
        cout<<strStr("","")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
