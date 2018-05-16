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
    int numDecodings(string s) {
        int N = s.length();
        if(!N) return 0;
        vector<int> D(N+2,1);
        D[N - 1] = s[N - 1] >= '1' && s[N - 1] <= '9';
        
        for(int i = N - 2 ; i >= 0 ; --i){
            int CntOne = s[i] >= '1' && s[i] <= '9';
            int Num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            int CntTwo = Num >= 10 && Num <= 26;
            
            D[i] = CntOne * D[i + 1] + CntTwo * D[i + 2];
        }
        return s[0] == '0' ? 0 : D[0];
    }
    
    void Test(){
        cout<<numDecodings("101")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
