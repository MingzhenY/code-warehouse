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
/*
 1.Record A[i]+A[j] for each pair of i,j
 Add: O(n)
 Find: O(1)
 Result: TLE
 
 2.Use BST with pointers to neibours.
 Add: O(log(n))
 Find: O(n) using two pointers
 */

class TwoSum1 {
#define LL long long
    list<int> Vals;
    set<LL> S;
public:
    /** Initialize your data structure here. */
    TwoSum1() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        for(auto x: Vals){
            S.insert((LL)x+number);
        }
        Vals.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        return S.count(value);
    }
};

class TwoSum2 {
    multiset<int> S;
public:
    /** Initialize your data structure here. */
    TwoSum2() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        S.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        set<int>::iterator L = S.begin(), R = S.end();
        if(L == R) return false;
        --R;
        while(L != R){
            if(*L + *R == value){
                return true;
            }
            if(*L + *R > value){
                --R;
            }
            else{
                ++L;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main(){
    TwoSum2 S;
    S.add(1);S.add(3);S.add(5);
    cout<<S.find(4)<<" "<<S.find(7)<<endl;
	return 0;
}
