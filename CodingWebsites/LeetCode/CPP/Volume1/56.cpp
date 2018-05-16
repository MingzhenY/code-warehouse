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
private:
    static bool cmp(const Interval &A,const Interval &B){
        return A.start < B.start || (A.start == B.start && A.end < B.end);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int N = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        if(N <= 1) return intervals;
        bool empty = true;
        int start;
        int end;
        vector<Interval> ANS;
        for(int i = 0 ; i < N ; ++i){
            if(empty){
                //set
                start = intervals[i].start;
                end = intervals[i].end;
                empty = false;
            }
            else{
                //merge
                end = max(end,intervals[i].end);
            }
            if(i + 1 == N || intervals[i + 1].start > end){
                //record answer
                ANS.push_back(Interval(start,end));
                //reset
                empty = true;
            }
        }
        
        return ANS;
    }
    void Test(){
        vector<Interval> V;
        V.push_back(Interval(1,4));
        V.push_back(Interval(2,3));
        V.push_back(Interval(8,9));
        
        vector<Interval> ANS = merge(V);
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
