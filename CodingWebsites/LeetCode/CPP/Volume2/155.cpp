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
using namespace std;

class MinStack {
    list<int> Val,Min;
    int n;
public:
    /** initialize your data structure here. */
    MinStack() {
        n = 0;
        Min.push_back((1<<31)-1);
    }
    
    void push(int x) {
        n++;
        Val.push_back(x);
        Min.push_back(min(Min.back(),x));
    }
    
    void pop() {
        if(n--){
            Val.pop_back();
            Min.pop_back();
        }
    }
    
    int top() {
        return n > 0 ? Val.back() : 0;
    }
    
    int getMin() {
        return n > 0 ? Min.back() : 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
class Solution {
public:
    MinStack MS;
    void Test(){
        MS.push(3);
        MS.push(1);
        MS.push(5);
        cout<<MS.top()<<" ";
        cout<<MS.getMin()<<endl;
        MS.pop();
        cout<<MS.top()<<" ";
        cout<<MS.getMin()<<endl;
        MS.pop();
        cout<<MS.top()<<" ";
        cout<<MS.getMin()<<endl;
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
