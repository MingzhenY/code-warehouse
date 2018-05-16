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
#include <stack>
using namespace std;

class Solution {
private:
    struct Op{
        char op;//0 for number, ASCII value for '+', '-',' (', ')'
        int value;
        Op(int op,int value = 0):op(op),value(value){}
    };
public:
    int calculate(string s) {
        vector<Op> oplist = Filter(s);
        stack<Op> S;
        S.push(Op('+',0));
        for(auto x : oplist){
            Op o = S.top();
            if(x.op){
                switch(x.op){
                    case '+':
                        S.pop();
                        S.push(Op('+',o.value));
                        break;
                    case '-':
                        S.pop();
                        S.push(Op('-',o.value));
                        break;
                    case '(':
                        S.push(Op('+',0));
                        break;
                    case ')':
                        S.pop();
                        Op last = S.top();
                        S.pop();
                        S.push(Op(0,last.op == '+'?last.value + o.value:last.value-o.value));
                }
            }
            else{
                S.pop();
                switch(o.op){
                    case '+': S.push(Op(0,o.value + x.value));break;
                    case '-': S.push(Op(0,o.value - x.value));break;
                    default:  printf("ERROR!\n");
                }
            }
        }
        return S.top().value;
    }
    vector<Op> Filter(string s){
        int n = s.length();
        vector<Op> oplist;
        for(int i = 0 ; i < n ;){
            if(s[i] >= '0' && s[i] <= '9'){
                int j = i;
                while(j < n && s[j] >= '0' && s[j] <= '9') ++j;
                //[i,j) is the number;
                int num = 0;
                for(int k = i ; k < j ; ++k){
                    num = num * 10 + s[k] - '0';
                }
                oplist.push_back(Op(0,num));
                i = j;
            }
            else{
                switch(s[i]){
                    case '+': oplist.push_back(Op('+'));break;
                    case '-': oplist.push_back(Op('-'));break;
                    case '(': oplist.push_back(Op('('));break;
                    case ')': oplist.push_back(Op(')'));break;
                }
                ++i;
            }
        }
        return oplist;
    }
    void ShowOp(vector<Op> &oplist){
        for(auto x:oplist){
            if(x.op) printf("%c",x.op);
            else printf("%d",x.value);
        }
        printf("\n");
    }
    void Test(){
        string s1 = "1";
        cout<<calculate(s1)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
