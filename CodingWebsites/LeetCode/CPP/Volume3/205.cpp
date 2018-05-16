#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> VS = getD(s);
        vector<int> VT = getD(t);
        for(int i = 0 ; i < VS.size() ; i++){
            if(VS[i] != VT[i])
                return false;
        }
        return true;
    }
    vector<int> getD(string &str){
        int n = str.length();
        vector<int> V(n,0);
        map<char,int> M;
        int ID = 1;
        for(int i = 0 ; i < n ; i++){
            int id = M[str[i]] ? : M[str[i]] = ID++;
            V[i] = id;
        }
        return V;
    }
    void Test(){
        cout<<isIsomorphic("egg","add")<<endl;
        cout<<isIsomorphic("foo","bar")<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
