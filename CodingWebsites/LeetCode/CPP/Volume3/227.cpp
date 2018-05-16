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
        char op;//0 for number, ASCII value for '+', '-','*','/','(', ')'
        int value;
        Op(int op,int value = 0):op(op),value(value){}
    };
#define NUM 1
#define EXP 2
#define TERM 3
#define FAC 4
#define PLUS 5
#define MINUS 6
#define TIMES 7
#define DIV 8
#define LP 9
#define RP 10
#define END 11
public:
    int calculate(string s) {
        vector<Op> oplist = Filter(s);
        oplist.push_back(Op('$'));
        stack<int> State;
        stack<Op> Symbol;
        State.push(0);
        for(int i = 0 ; i < oplist.size() ; ++i){
            //printf("i = %d, State = %d, Symbol = (%d,%d)\n",i,
            //      State.top(), Symbol.empty()?-1:Symbol.top().op,Symbol.empty()?-1:Symbol.top().value);
            Op op = oplist[i];
            int cntSymbol;
            int cntValue;
            switch(op.op){
                case '+': cntSymbol = PLUS; break;
                case '-': cntSymbol = MINUS; break;
                case '*': cntSymbol = TIMES; break;
                case '/': cntSymbol = DIV; break;
                case '(': cntSymbol = LP; break;
                case ')': cntSymbol = RP; break;
                case '$': cntSymbol = END; break;
                default: cntSymbol = NUM; cntValue = op.value;
            }
            int cntState = State.top();
            switch(cntState){
                case 0:
                case 4:
                case 6:
                case 7:
                    if(cntSymbol == NUM){
                        State.push(5);
                        Symbol.push(Op(NUM,cntValue));
                    }
                    else if(cntSymbol == LP){
                        State.push(4);
                        Symbol.push(Op(LP));
                    }
                    else{
                        return -1;
                    }
                    break;
                case 1:
                    if(cntSymbol == PLUS || cntSymbol == MINUS){
                        State.push(6);
                        Symbol.push(Op(cntSymbol));
                    }
                    else if(cntSymbol == END){
                        break;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 2:
                    if(cntSymbol == TIMES || cntSymbol == DIV){
                        State.push(7);
                        Symbol.push(Op(cntSymbol));
                    }
                    else if(cntSymbol == PLUS || cntSymbol == MINUS ||
                            cntSymbol == RP || cntSymbol == END){
                        //reduce using exp->term
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(1);break;
                            case 4:
                                State.push(8);break;
                            default:
                                return -1;
                        }
                        Op opx = Symbol.top();
                        Symbol.pop();
                        Symbol.push(Op(EXP,opx.value));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 3:
                    if(cntSymbol == PLUS || cntSymbol == MINUS ||
                       cntSymbol == TIMES || cntSymbol == DIV ||
                       cntSymbol == RP || cntSymbol == END){
                        //reduce by term -> fac
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(2);break;
                            case 4:
                                State.push(2);break;
                            case 6:
                                State.push(9);break;
                            default:
                                return -1;
                        }
                        Op opx = Symbol.top();
                        Symbol.pop();
                        Symbol.push(Op(TERM,opx.value));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 5:
                    if(cntSymbol == PLUS || cntSymbol == MINUS ||
                       cntSymbol == TIMES || cntSymbol == DIV ||
                       cntSymbol == RP || cntSymbol == END){
                        //reduce by fac->NUM
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(3);break;
                            case 4:
                                State.push(3);break;
                            case 6:
                                State.push(3);break;
                            case 7:
                                State.push(10);break;
                            default:
                                return -1;
                        }
                        Op opx = Symbol.top();
                        Symbol.pop();
                        Symbol.push(Op(FAC,opx.value));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 8:
                    if(cntSymbol == PLUS || cntSymbol == MINUS){
                        State.push(6);
                        Symbol.push(Op(cntSymbol));
                    }
                    else if(cntSymbol == RP){
                        State.push(11);
                        Symbol.push(Op(cntSymbol));
                    }
                    else {
                        return -1;
                    }
                    break;
                case 9:
                    if(cntSymbol == TIMES || cntSymbol == DIV){
                        State.push(7);
                        Symbol.push(Op(cntSymbol));
                    }
                    else if(cntSymbol == PLUS || cntSymbol == MINUS ||
                            cntSymbol == RP || cntSymbol == END){
                        //reduce by exp->exp + term
                        State.pop();
                        State.pop();
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(1);break;
                            case 4:
                                State.push(8);break;
                            default:
                                return -1;
                        }
                        int A,OP,B,V;
                        B = Symbol.top().value; Symbol.pop();
                        OP = Symbol.top().op; Symbol.pop();
                        A = Symbol.top().value; Symbol.pop();
                        if(OP == PLUS) V = A + B;
                        else V = A - B;
                        Symbol.push(Op(EXP,V));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 10:
                    if(cntSymbol == TIMES || cntSymbol == DIV ||
                       cntSymbol == PLUS || cntSymbol == MINUS ||
                       cntSymbol == RP || cntSymbol == END){
                        //reduce by term -> term * fac
                        State.pop();
                        State.pop();
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(2);break;
                            case 4:
                                State.push(2);break;
                            case 6:
                                State.push(9);break;
                            default:
                                return -1;
                        }
                        int A,OP,B,V;
                        B = Symbol.top().value; Symbol.pop();
                        OP = Symbol.top().op; Symbol.pop();
                        A = Symbol.top().value; Symbol.pop();
                        if(OP == TIMES) V = A * B;
                        else V = A / B;
                        Symbol.push(Op(EXP,V));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
                case 11:
                    if(cntSymbol == TIMES || cntSymbol == DIV ||
                       cntSymbol == PLUS || cntSymbol == MINUS ||
                       cntSymbol == RP || cntSymbol == END){
                        //reduce by fac -> ( exp )
                        State.pop();
                        State.pop();
                        State.pop();
                        cntState = State.top();
                        switch(cntState){
                            case 0:
                                State.push(3);break;
                            case 4:
                                State.push(3);break;
                            case 6:
                                State.push(3);break;
                            case 7:
                                State.push(10);break;
                            default:
                                return -1;
                        }
                        int V;
                        Symbol.pop();
                        V = Symbol.top().value; Symbol.pop();
                        Symbol.pop();
                        Symbol.push(Op(FAC,V));
                        --i;
                    }
                    else{
                        return -1;
                    }
                    break;
            }
        }
        return Symbol.top().value;
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
                    case '*': oplist.push_back(Op('*'));break;
                    case '/': oplist.push_back(Op('/'));break;
                    case '(': oplist.push_back(Op('('));break;
                    case ')': oplist.push_back(Op(')'));break;
                }
                ++i;
            }
        }
        return oplist;
    }
    void Test(){
        string s1 = "1 + 7 / 2 * (8 - 7)";
        cout<<calculate(s1)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
