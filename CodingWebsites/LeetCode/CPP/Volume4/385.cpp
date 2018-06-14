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
 
class Solution {
    NestedInteger D(string &s,int L,int &R){//[L,R)
        if(s[L] == '['){
            if(s[L + 1] == ']'){
                R = L + 2;
                return NestedInteger();
            }
            NestedInteger ret;
            int cntR,cntL = L + 1;
            while(true){
                NestedInteger t = D(s,cntL,cntR);
                ret.add(t);
                if(s[cntR] == ']')
                    break;
                else
                    cntL = cntR + 1;
            }
            R = cntR + 1;
            return ret;
        }
        else{
            int V = 0, sign = 1;
            if(s[L] == '-'){
                L++;
                sign = -1;
            }
            for(R = L ; R < s.length() && s[R] >= '0' && s[R] <= '9'; ++R){
                V = V * 10 + s[R] - '0';
            }
            return NestedInteger(V * sign);
        }
    }
public:
    NestedInteger deserialize(string s) {
        int R;
        return D(s,0,R);
    }
    void Test(){
        string s = "[-2,[3,4,[4,[7,8],6]],[]]";
        NestedInteger N = deserialize(s);
        N.Show();
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
