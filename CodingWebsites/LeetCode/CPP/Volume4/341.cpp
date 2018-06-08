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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    bool ready;//if the next value is ready
    int NextValue;
    stack<vector<NestedInteger> *> S;
    stack<int> I;
    void getNext(){
        while(ready = !S.empty()){
            vector<NestedInteger> *t = S.top();
            int i = I.top();
            if(i < t->size()){
                //Current Vector is not over, evaluate next element
                
                I.pop();
                I.push(i + 1);
                //evaluating (*t)[i]
                if((*t)[i].isInteger()){
                    //Is integer, record and break
                    NextValue = (*t)[i].getInteger();
                    break;
                }
                else{
                    //Is list, push to stack
                    S.push(&((*t)[i].getList()));
                    I.push(0);
                }
            }
            else{
                //CurrentList is over, pop
                S.pop();
                I.pop();
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        S.push(&nestedList);
        I.push(0);
        ready = true;
        getNext();
    }

    int next() {
        int Value = NextValue;
        getNext();
        return Value;
    }

    bool hasNext() {
        return ready;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
