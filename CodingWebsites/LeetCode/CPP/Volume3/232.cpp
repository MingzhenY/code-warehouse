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


class MyQueue {
    stack<int> L,R;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!R.empty()){
            L.push(R.top());
            R.pop();
        }
        R.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!L.empty()){
            R.push(L.top());
            L.pop();
        }
        int V = R.top();
        R.pop();
        return V;
    }
    
    /** Get the front element. */
    int peek() {
        while(!L.empty()){
            R.push(L.top());
            L.pop();
        }
        return R.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return L.empty() && R.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
