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


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    vector<NestedInteger> List;
    int val;
    bool isVal;
public:
    // Constructor initializes an empty nested list.
    NestedInteger(){
        isVal = false;
    }
    // Constructor initializes a single integer.
    NestedInteger(int value){
        isVal = true;
        val = value;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{
        return isVal;
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{
        return val;
    }
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value){
        val = value;
        isVal = true;
    }
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni){
        isVal = false;
        List.push_back(ni);
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{
        return List;
    }
    void Show(bool newline = true){
        if(isVal)
            printf("%d",val);
        else{
            printf("[");
            int N = List.size();
            for(int i = 0 ; i < N ; ++i){
                List[i].Show(false);
                if(i + 1 < N) printf(",");
            }
            printf("]");
        }
        if(newline)
            printf("\n");
    }
};
void Test(){
    NestedInteger A(5),B(7),C(8),D(9),E(11);
    NestedInteger X;
    X.add(A);
    X.add(B);
    X.add(C);
    C.add(X);
    C.add(E);
    D.add(C);
    D.add(X);
    D.Show();
}

int main(){
    Test();
    return 0;
}
