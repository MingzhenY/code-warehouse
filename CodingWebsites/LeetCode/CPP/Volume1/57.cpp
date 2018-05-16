#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ANS;
        int N = intervals.size();
        bool done = false;
        for(int i = 0 ; i < N ; ++i){
            if(intervals[i].end < newInterval.start){
                ANS.push_back(intervals[i]);
                continue;
            }
            if(intervals[i].start > newInterval.end){
                if(!done){
                    ANS.push_back(newInterval);
                    done = true;
                }
                ANS.push_back(intervals[i]);
                continue;
            }
            newInterval.start = min(newInterval.start,intervals[i].start);
            newInterval.end = max(newInterval.end,intervals[i].end);
        }
        if(!done){
            ANS.push_back(newInterval);
            done = true;
        }
        return ANS;
    }
    void Test(){
        vector<Interval> V;
        V.push_back(Interval(1,4));
        V.push_back(Interval(5,7));
        V.push_back(Interval(8,9));
        
        vector<Interval> ANS = insert(V,Interval(7,8));
        for(auto i:ANS){
            printf("[%d,%d)\n",i.start,i.end);
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
