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
    vector<string> restoreIpAddresses(string s) {
        int N = s.length();
        if(N < 4 || N > 12) return vector<string>();
        vector<string> ANS;
        for(int L1 = 1 ; L1 <= 3 ; ++L1){
            for(int L2 = 1 ; L2 <= 3 ; ++L2){
                for(int L3 = 1 ; L3 <= 3 ; ++L3){
                    for(int L4 = 1 ; L4 <= 3 ; ++L4){
                        if(L1 + L2 + L3 + L4 != N) continue;
                        int A1 = 0, A2 = 0, A3 = 0, A4 = 0;
                        for(int i = 0 ; i < L1 ; ++i) A1 = A1 * 10 + s[i] - '0';
                        for(int i = L1 ; i < L1 + L2 ; ++i) A2 = A2 * 10 + s[i] - '0';
                        for(int i = L1 + L2 ; i < N - L4 ; ++i) A3 = A3 * 10 + s[i] - '0';
                        for(int i = L1 + L2 + L3 ; i < N ; ++i) A4 = A4 * 10 + s[i] - '0';
                        if(!checkAL(A1,L1) ||
                           !checkAL(A2,L2) ||
                           !checkAL(A3,L3) ||
                           !checkAL(A4,L4)) continue;
                        char tempStr[16];
                        sprintf(tempStr,"%d.%d.%d.%d",A1,A2,A3,A4);
                        ANS.push_back(tempStr);
                    }
                }
            }
        }
        return ANS;
    }
    bool checkAL(int A, int L){
        return
        L == 1 ? A >= 0 && A <= 9 :
        L == 2 ? A >= 10 && A <= 99 :
        L == 3 ? A >= 100 && A <= 255 :
        false;
    }
    void Test(){
        string str = "25525511135";
        str = "010010";
        vector<string> ANS = restoreIpAddresses(str);
        for(auto x:ANS){
            cout<<x<<endl;
        }
        cout<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
