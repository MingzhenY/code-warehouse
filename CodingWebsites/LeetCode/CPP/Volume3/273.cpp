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
    vector<string> Under20;
    vector<string> Tens;
    vector<string> O;
public:
    Solution(){
        Under20 = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
            "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
            "Seventeen","Eighteen","Nineteen"};
        Tens = {"Zero","Tenth","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        O = {"Hundred","Thousand","Million","Billion","Trillion","Quadrillion"};
    }
    string numberToWords(int num) {
        //at most 10 digits
        int L3 = num / 1000000000;
        num -= L3 * 1000000000;
        int L2 = num / 1000000;
        num -= L2 * 1000000;
        int L1 = num / 1000;
        num -= L1 * 1000;
        int L0 = num;
        string pre = "";
        string ret;
        if(L3) ret += Say(L3,pre) + " " + O[3];
        if(L2) ret += Say(L2,pre) + " " + O[2];
        if(L1) ret += Say(L1,pre) + " " + O[1];
        if(L0) ret += Say(L0,pre);
        return ret != "" ? ret : "Zero";
    }
    string Say(int num,string &pre){
        // num < 1000
        int L2 = num / 100, L1 = (num % 100) / 10, L0 = num % 10;
        string ret;
        if(L2) {
            ret = ret + pre + Under20[L2] + " " + O[0];
            pre = " ";
        }
        if(L1 >= 2){
            ret = ret + pre + Tens[L1];
            if(L0) ret += " " + Under20[L0];
            pre = " ";
        }
        else{
            if(L0 || L1){
                //if(L2 > 0 && L1 == 0) ret += " And";
                ret += pre + Under20[10 * L1 + L0];
                pre = " ";
            }
        }
        return ret;
    }
    void Test(){
        cout<<numberToWords(20)<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
