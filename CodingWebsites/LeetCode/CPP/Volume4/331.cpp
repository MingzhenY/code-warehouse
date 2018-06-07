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
    string split(string preorder){
        int L = preorder.length();
        int p = -1;
        string ret;
        for(int i = 0 ; i <= L ; ++i){
            if(i == L || preorder[i] == ','){
                //[p+1,i)
                char ch = preorder[p+1] == '#'? '#' : 'N';
                ret += ch;
                p = i;
            }
        }
        return ret;
    }
    bool getT(string &str, int &X, int L){
        if(getEmpty(str,X,L))
            return true;
        
        bool ret = true;
        ret = ret && getNum(str,X,L);
        ret = ret && getT(str,X,L);
        ret = ret && getT(str,X,L);
        return ret;
    }
    bool getNum(string &str, int &X, int L){
        if(X < L && str[X] == 'N'){
            ++X;
            return true;
        }
        else{
            return false;
        }
    }
    bool getEmpty(string &str, int &X, int L){
        if(X < L && str[X] == '#'){
            ++X;
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool isValidSerialization(string preorder) {
        string str = split(preorder);
        int X = 0, L = str.length();
        return getT(str,X,L) && X == L;
    }
    void Test(){
        printf("%d\n",isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
        printf("%d\n",isValidSerialization("9,#,#,1"));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
