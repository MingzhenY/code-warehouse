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
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<int,vector<string>> Group;
        for(auto str:strings){
            Group[hash(str)].push_back(str);
        }
        vector<vector<string>> ret;
        for(auto x:Group){
            ret.push_back(x.second);
        }
        return ret;
    }
    int hash(string str){
        int n = str.length();
        if(n <= 1) return -1;
        int H = 0;
        for(int i = 1 ; i < n ; ++i){
            int C = (str[i] + 26 - str[i - 1]) % 26;
            H = H * 137 + C + 37;
        }
        return H;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
