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

class MyStack {
private:
    queue<int> Q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int N = Q.size();
        for(int i = N - 1 ; i >= 0 ; --i){
            int V = Q.front();Q.pop();
            if(i){
                Q.push(V);
            }
            else return V;
        }
        return 0;
    }
    
    /** Get the top element. */
    int top() {
        int N = Q.size();
        for(int i = N - 1 ; i >= 0 ; --i){
            int V = Q.front();Q.pop();
            Q.push(V);
            if(!i) return V;
        }
        return 0;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main(){
    Solution S;
    S.Test();
	return 0;
}
