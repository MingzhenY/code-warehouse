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
#include <queue>
using namespace std;

class Solution {
private:
    //use map for simplicity
    map<char,int> M;
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //Use of two pointers:
        //Condition: [L,R) is not valid => [L, R+) is not valid
        //Functions: Init(),Add(i), Remove(i), isValid
        Init();
        int n = s.length();
        int L = 0, R = 0, MaxLen = 0;
        while(1){
            if(isValid()){
                MaxLen = max(MaxLen,R - L);
                if(R == n){
                    break;
                }
                else {
                    Add(R,s[R]);
                    R++;
                }
            }
            else{
                Remove(L,s[L]);
                L++;
            }
        }
        return MaxLen;
    }
    void Init(){
        M.clear();
    }
    bool isValid(){
        return M.size() <= 2;
    }
    void Add(int i,char ch){
        M[ch]++;
    }
    void Remove(int i,char ch){
        M[ch]--;
        if(M[ch] == 0){
            M.erase(ch);
        }
    }
    void Test(){
        string str = "ecebaba";
        cout<<lengthOfLongestSubstringTwoDistinct(str)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
