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
    bool isInterleave(string s1, string s2, string s3) {
        int Len1 = s1.length();
        int Len2 = s2.length();
        int Len3 = s3.length();
        if(Len3 != Len1 + Len2) return false;
        if(Len1 * Len2 <= 10000000){
            vector<vector<bool> > D(Len1 + 1, vector<bool>(Len2 + 1));
            D[0][0] = true;
            for(int i = 0 ; i <= Len1 ; ++i){
                for(int j = 0 ; j <= Len2 ; ++j){
                    if(i > 0 || j > 0){
                        bool LValid = i ? D[i - 1][j] && s1[i - 1] == s3[i + j - 1] : false;
                        bool RValid = j ? D[i][j - 1] && s2[j - 1] == s3[i + j - 1] : false;
                        D[i][j] = LValid || RValid;
                    }
                    else D[i][j] = true;//D[0][0] = true;
                }
            }
            return D[Len1][Len2];
        }
        else return false;
    }
    void Test(){
        string s1 = "aabcc";
        string s2 = "dbbca";
        cout<<isInterleave(s1,s2,"aadbbcbcac")<<endl;
        cout<<isInterleave(s1,s2,"aadbbbaccc")<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
