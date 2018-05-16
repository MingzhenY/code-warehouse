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
#include <stack>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(auto tk : tokens){
            if (tk == "+" ||
                tk == "-" ||
                tk == "*" ||
                tk == "/"){
                int R = S.top(); S.pop();
                int L = S.top(); S.pop();
                switch(tk[0]){
                    case '+':S.push(L + R);break;
                    case '-':S.push(L - R);break;
                    case '*':S.push(L * R);break;
                    case '/':S.push(L / R);break;
                }
            }
            else{
                S.push(stoi(tk));
            }
        }
        return S.top();
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
