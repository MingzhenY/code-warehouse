#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        list<string> L = SplitPath(path);
        //printf("L.size()=%lu\n",L.size());
        list<string> A;
        for(list<string>::iterator it = L.begin() ; it != L.end() ; ++it){
            if(*it == "."){
                
            }
            else if(*it == ".."){
                if(A.size() > 0){
                    A.pop_back();
                }
            }
            else{
                A.push_back(*it);
            }
        }
        string ANS = "/";
        bool first = true;
        for(list<string>::iterator it = A.begin() ; it != A.end() ; ++it){
            if(first) first = false;
            else ANS += "/";
            ANS += *it;
        }
        return ANS;
    }
    list<string> SplitPath(string path){
        list<string> ANS;
        path += '/';
        int N = path.length();
        int Last = 0;
        for(int i = 0 ; i < N ; ++i){
            if(path[i] == '/'){
                //(Last,i)
                if(Last + 1 < i){
                    ANS.push_back(path.substr(Last+1,i - Last - 1));
                }
                Last = i;
            }
        }
        return ANS;
    }
    void Test(){
        string path1 = "/...";
        string path2 = "/a/./b/../../c/";
        cout<<simplifyPath(path1)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
