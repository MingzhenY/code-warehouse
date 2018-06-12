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
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int getDepth(vector<NestedInteger>& nestedList){
        int Depth = 0;
        for(auto ni : nestedList){
            if(!ni.isInteger()){
                int D = getDepth(ni.getList());
                if(D > Depth)
                    Depth = D;
            }
        }
        return Depth + 1;
    }
    int DSI(vector<NestedInteger>& nestedList, int D, int Depth){
        int Sum = 0;
        for(auto ni : nestedList){
            if(ni.isInteger()){
                Sum += (Depth - D) * ni.getInteger();
            }
            else{
                Sum += DSI(ni.getList(), D + 1, Depth);
            }
        }
        return Sum;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int Dep = getDepth(nestedList);
        return DSI(nestedList,0,Dep);
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
