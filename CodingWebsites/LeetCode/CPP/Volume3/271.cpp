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

class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        //#len# + string
        for(auto x:strs){
            char header[64];
            sprintf(header,"#%lu#",x.length());
            ret = ret + header + x;
        }
        return ret;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int A = 0, Len = 0, n = s.length();
        vector<string> ret;
        for(int i = 0 ; i < n ; ++i){
            if(A){
                if(s[i] != '#'){
                    Len = Len * 10 + s[i] - '0';
                }
                else{
                    ret.push_back(s.substr(i + 1,Len));
                    i = i + Len;
                    A = 0;
                }
            }
            else{
                if(s[i] == '#'){
                    A = 1;
                    Len = 0;
                }
                else{
                    printf("Error at s[%lu]\n",ret.size()+1);
                }
            }
        }
        return ret;
    }
};

void Test(){
    Codec C;
    vector<string> strs = {"Once upon a time","The magicians","One more string",""};
    vector<string> ret = C.decode(C.encode(strs));
    for(auto str : ret){
        cout<<"["<<str<<"]"<<endl;
    }
}
int main(){
    Test();
	return 0;
}
