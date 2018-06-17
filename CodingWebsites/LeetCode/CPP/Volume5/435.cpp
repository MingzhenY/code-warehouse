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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool LT(const Interval &A,const Interval &B){
    return A.start < B.start ||
            (A.start == B.start && A.end < B.end);
}

class Solution {
    int BinarySearch(vector<int> &DP,vector<Interval>& intervals,int L,int R, int V){
        if(V > intervals[R].start) return -1;
        while(L ^ R){//[L,R] find first >= V
            int M = (L + R) >> 1;
            if(intervals[M].start >= V)
                R = M;
            else
                L = M + 1;
        }
        return L;
    }
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        //For intervals that have the same start
        //only keep the one with the smallest end
        sort(intervals.begin(),intervals.end(),LT);
        int N = intervals.size();
        if(!N) return 0;
        int OriginalN = N;
        if(N > 1){
            int I = 1;
            for(int i = 1 ; i < N ; ++i){
                if(intervals[i].start != intervals[i - 1].start){
                    intervals[I++] = intervals[i];
                }
            }
            N = I;
        }
        //now dp
        //DP[k] = max ans for intervals[k..N)
        vector<int> DP(N);
        DP[N - 1] = 1;
        for(int i = N - 2 ; i >= 0 ; --i){
            //current interval ends at intervals[i].end
            //Find the first start that is >= cnt end
            int FirstStart = BinarySearch(DP,intervals,i+1,N-1,intervals[i].end);
            if(FirstStart != -1)
                DP[i] = max(DP[i + 1],1 + DP[FirstStart]);
            else
                DP[i] = DP[i + 1];
        }
        return OriginalN - DP[0];
    }
    void Test(){
        vector<Interval> V;
        V.push_back(Interval(1,3));
        V.push_back(Interval(3,4));
        V.push_back(Interval(3,7));
        printf("%d\n",eraseOverlapIntervals(V));
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
