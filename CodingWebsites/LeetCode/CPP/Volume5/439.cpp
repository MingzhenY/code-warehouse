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
    string eval(string &expr, int L,int &R,int N){
        if(expr[L] >= '0' && expr[L] <= '9'){
            R = L + 1;
            string ret;
            ret += expr[L];
            return ret;
        }
        
        if(L + 1 < N && expr[L + 1] == '?'){
            //match T = B ? T : T
            string vT = eval(expr,L + 2,R,N);
            //cout<<expr.substr(L+2,R-L-2)<<endl;
            
            if(expr[R] != ':')
                return "ERROR";
            string vF = eval(expr,R + 1,R,N);
            if(expr[L] == 'T')
                return vT;
            else
                return vF;
        }
        else{
            R = L + 1;
            string ret;
            ret += expr[L];
            return ret;
        }
    }
public:
    string parseTernary(string expression) {
        int R;
        return eval(expression,0,R,expression.length());
    }
    void Test(){
        cout<<parseTernary("T?T?1:2:3")<<endl;
        cout<<parseTernary("T?F?1:2:3")<<endl;
        cout<<parseTernary("F?T?1:2:3")<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
