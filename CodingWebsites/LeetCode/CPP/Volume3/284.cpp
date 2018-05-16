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

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    Iterator PeekIterator;
    bool Valid;
    int Value;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums),PeekIterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if(PeekIterator.hasNext()){
            Value = PeekIterator.next();
            Valid = true;
        }
        else{
            Valid = false;
        }
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return Valid ? Value : -1;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int V = Iterator::next();
        if(PeekIterator.hasNext()){
            Value = PeekIterator.next();
            Valid = true;
        }
        else{
            Valid = false;
        }
        return V;
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

int main(){
    
	return 0;
}
