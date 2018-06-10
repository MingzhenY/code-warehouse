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

//Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 bool Interval_LT(const Interval &A,const Interval &B){
    return A.start < B.start || 
        (A.start == B.start && A.end < B.end);
 }
 bool Interval_EQ(Interval &A, Interval &B){
    return A.start == B.start && A.end == B.end;
 }

struct DATA{
    int N;
    vector<list<Interval>> S,E;
    set<int> In;
    DATA(){}
    DATA(int size){
        N = size;
        S = vector<list<Interval>>(N);
        E = vector<list<Interval>>(N);
    }
    int hash(int x){
        return ((x * 2654289839) % N + N) % N;
    }
    void AddInterval(Interval I){
        S[hash(I.start)].push_back(I);
        E[hash(I.end)].push_back(I);
    }
    void Delete(list<Interval> &L, Interval I){
        list<Interval> :: iterator del = L.end();
        for(auto it = L.begin() ; it != L.end() ; ++it){
            if(it->start == I.start && it->end == I.end)
                del = it;
        }
        if(del != L.end()){
            L.erase(del);
        }
    }
    void DeleteInterval(list<Interval>::iterator it){
        int start = it->start;
        int end = it->end;
        Delete(S[hash(start)],Interval(start,end));
        Delete(E[hash(end)],Interval(start,end));
    }
    list<Interval>::iterator FindLeft(Interval I, int &H){
        H = hash(I.start);
        for(auto it = E[H].begin(); it != E[H].end() ; ++it){
            if(it->end == I.start)
                return it;
        }
        return E[H].end();
    }
    list<Interval>::iterator FindRight(Interval I, int &H){
        H = hash(I.end);
        for(auto it = S[H].begin(); it != S[H].end() ; ++it){
            if(it->start == I.end)
                return it;
        }
        return S[H].end();
    }
    void AddNum(int val){
        //check if val has alreqady been added
        if(In.count(val)) return;
        In.insert(val);
        Interval x = Interval(val,val+1);
        int HL,HR;
        auto li = FindLeft(x,HL);
        auto ri = FindRight(x,HR);
        
        int start = val, end = val + 1;
        if(li != E[HL].end()){
            start = li->start;
            DeleteInterval(li);
        }
        if(ri != S[HR].end()){
            end = ri->end;
            DeleteInterval(ri);
        }
        AddInterval(Interval(start,end));
    }
    vector<Interval> getIntervals(){
        vector<Interval> ret;
        for(auto l : S){
            for(auto x:l){
                ret.push_back(Interval(x.start,x.end-1));
            }
        }
        sort(ret.begin(),ret.end(),Interval_LT);
        return ret;
    }
    void Show(){
        vector<Interval> ret = getIntervals();
        for(auto x:ret){
            printf("[%d,%d]\n",x.start,x.end);
        }
    }
    void Test(){
        srand(time(NULL));
        vector<Interval> VI;
        VI.push_back(Interval(1,2));
        VI.push_back(Interval(3,4));
        VI.push_back(Interval(5,7));
        for(auto i : VI){
            AddInterval(i);
        }
        AddNum(2);
        Show();
    }
};


class SummaryRanges {
    DATA D;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        D = DATA(100);
    }
    
    void addNum(int val) {
        D.AddNum(val);
    }
    
    vector<Interval> getIntervals() {
        return D.getIntervals();
    }
    void Show(){
        vector<Interval> ANS = getIntervals();
        for(auto x:ANS){
            printf("[%d,%d)\n",x.start,x.end);
        }
    }
    void Test(){
        
        SummaryRanges SR;
        SR.addNum(2);
        SR.addNum(4);
        SR.addNum(6);
        SR.addNum(3);
        SR.addNum(5);
        SR.Show();
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main(){
    SummaryRanges S;
    S.Test();
	return 0;
}
