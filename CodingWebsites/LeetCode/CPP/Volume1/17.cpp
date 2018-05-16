#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
private:
    
public:
    vector<string> letterCombinations(string digits) {
        int N = digits.size();
        if(0 == N) return vector<string>();
        bool Valid[10] = {false,false,true,true,true,true,true,true,true,true};
        int Start[10] = {-1,-1,'a','d','g','j','m','p','t','w'};
        int End[10] = {-1,-1,'c','f','i','l','o','s','v','z'};
        vector<int> Cnt(N,0);
        for(int i = 0 ; i < N ; ++i) Cnt[i] = 0;
        for(int i = 0 ; i < N ; ++i) digits[i] -= '0';
        string Str(digits);
        int Top = 0;
        Cnt[0] = Start[digits[0]] - 1;
        vector<string> ANS;
        while(1){
            if(Top == N){
                //Record
                ANS.push_back(Str);
                //Reduce
                --Top;
                continue;
            }
           
            if(Cnt[Top] >= End[digits[Top]]){
                //Reduce
                if(--Top < 0) break;
            }
            else{
                //Update
                Str[Top] = ++Cnt[Top];
                //Advance
                if(++Top < N){
                    Cnt[Top] = Start[digits[Top]] - 1;
                }
            }
        }
        return ANS;
    }
    void Test(){
        string str = "";
        
        vector<string> ANS = letterCombinations(str);
        for(auto s : ANS){
            cout<<s<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
