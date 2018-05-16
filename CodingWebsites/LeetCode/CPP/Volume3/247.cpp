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
    map<char,char> rotate180;
public:
    Solution(){
        rotate180['0'] = '0';
        rotate180['1'] = '1';
        rotate180['6'] = '9';
        rotate180['8'] = '8';
        rotate180['9'] = '6';
    }
    vector<string> findStrobogrammatic(int n) {
        //first = 1689
        //between = 01689
        //middle = 018
        int Half = (n - 1) / 2;
        string str;
        vector<string> ret;
        find(ret,str,0,Half,n);
        return ret;
    }
    void find(vector<string> &ret,string &str,int i,int n,int orglen){
        if(i > n){
            string s = str;
            int len = str.length();
            for(int i = orglen / 2 - 1 ; i >= 0 ; --i){
                s += rotate180[str[i]];
            }
            ret.push_back(s);
            return;
        }
        if(i || orglen == 1){
            str += "0";
            find(ret,str,i+1,n,orglen);
            str = str.substr(0,str.length()-1);
        }
        {
            str += "1";
            find(ret,str,i+1,n,orglen);
            str = str.substr(0,str.length()-1);
            str += "8";
            find(ret,str,i+1,n,orglen);
            str = str.substr(0,str.length()-1);
        }
        if((orglen & 1) && i == n){
            
        }
        else{
            str += "6";
            find(ret,str,i+1,n,orglen);
            str = str.substr(0,str.length()-1);
            str += "9";
            find(ret,str,i+1,n,orglen);
            str = str.substr(0,str.length()-1);
        }
    }
    void Test(){
        vector<string> ret = findStrobogrammatic(10);
        cout<<ret.size()<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
