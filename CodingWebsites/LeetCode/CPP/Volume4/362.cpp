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

class HitCounter {
    list<pair<int,int>> L;
    int LastTS, Count, Sum;
    void Update(int timestamp){
        while(!L.empty()){
            pair<int,int> p = *L.begin();
            if(p.first + 300 <= timestamp){
                L.pop_front();
                Sum -= p.second;
            }
            else
                break;
        }
    }
public:
    /** Initialize your data structure here. */
    HitCounter() {
        LastTS = -1;
        Count = 0;
        Sum = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(timestamp != LastTS){
            L.push_back(make_pair(LastTS,Count));
            Sum += Count;
            LastTS = timestamp;
            Count = 1;
        }
        else{
            ++Count;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        Update(timestamp);
        int D = LastTS + 300 > timestamp ? Count : 0;
        return D + Sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main(){
    Solution S;
    S.Test();
	return 0;
}
