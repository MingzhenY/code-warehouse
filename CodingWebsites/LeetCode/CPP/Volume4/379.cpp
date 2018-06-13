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

class PhoneDirectory {
    set<int> Used, Free;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0 ; i < maxNumbers ; ++i)
            Free.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(!Free.empty()){
            int k = *Free.begin();
            Free.erase(k);
            Used.insert(k);
            return k;
        }
        else
            return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return Free.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(Used.count(number)){
            Used.erase(number);
            Free.insert(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
