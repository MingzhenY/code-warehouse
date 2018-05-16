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
 
class Solution1 {
    /*
     Segment Tree:
     cut x-axis in to segments using end points of each line.
     for each line, increase the segment count by 1 for segments inside this line
     the highest segment count is the answer
     */
    //Rank
    int Rn;
    vector<int> Rank;
    void setRank(){
        //sort
        sort(Rank.begin(),Rank.end());
        //eliminate duplicates
        int N = Rank.size();
        Rn = 1;
        for(int i = 1 ; i < N ; ++i)
            if(Rank[i] != Rank[i - 1])
                Rank[Rn++] = Rank[i];
        Rank.resize(Rn);
    }
    int getRank(int V){
        int L = 0 , R = Rn;//[L,R)
        while(L + 1 < R){//find last <= V
            int M = (L + R) >> 1;
            if(Rank[M] <= V) L = M;
            else R = M;
        }
        return L;
    }
    //non-recursive segment tree
    int N;
    vector<int> ST;
    void Init(){
        N = 1;
        while(N < Rn + 2) N <<= 1;
        ST = vector<int>(N << 1,0);
    }
    void Update(int L,int R){
        for(int s = N + L - 1, t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1, t >>= 1){
            if(~s & 1) ++ST[s ^ 1];
            if( t & 1) ++ST[t ^ 1];
        }
    }
    int PushDownAll(){
        for(int i = 1 ; i < N ; ++i){
            ST[i << 1] += ST[i];
            ST[i << 1 | 1] += ST[i];
        }
        int MAX = 0;
        for(int i = 1 , j = N + 1 ; i < Rn ; ++i, ++j)
            MAX = max(MAX,ST[j]);
        return MAX;
    }
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        Rank = vector<int>();
        for(auto x:intervals){
            Rank.push_back(x.start);
            Rank.push_back(x.end);
        }
        setRank();
        Init();
        for(auto x:intervals)
            Update(getRank(x.start) + 1, getRank(x.end));
        return PushDownAll();
    }
    void Test(){
        
    }
};
class Solution {
    /*
     a simplified sweepline method
     An improvement(not implemented here): use map to store values with each X
     */
    struct Line{
        int x;
        bool in;
        Line(){}
        Line(int x,bool in):x(x),in(in){}
        bool operator < (const Line &B)const{
            return x < B.x;
        }
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        vector<Line> Lines;
        for(auto x:intervals){
            Lines.push_back(Line(x.start,true));
            Lines.push_back(Line(x.end,false));
        }
        sort(Lines.begin(),Lines.end());
        int n = Lines.size();
        int SegmentCount = 0;
        int MaxRoom = 0;
        int X = -1;
        int I = 0;
        while(I < n){
            X = Lines[I].x;
            while(Lines[I].x == X){
                if(Lines[I].in)
                    ++SegmentCount;
                else --SegmentCount;
                ++I;
            }
            MaxRoom = max(MaxRoom, SegmentCount);
        }
        return MaxRoom;
    }
    void Test(){
        
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
