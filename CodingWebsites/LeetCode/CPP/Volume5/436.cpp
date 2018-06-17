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

struct A{
    Interval I;
    int id;
    A(){}
    A(Interval I, int id):I(I),id(id){}
    bool operator <(const A & B)const{
        return I.start < B.I.start;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        //Assuming start points are different
        int N = intervals.size();
        vector<A> V(N);
        for(int i = 0 ; i < N ; ++i)
            V[i] = A(intervals[i],i);
        //sort by start value while keeping the original id
        sort(V.begin(),V.end());
        
        //D[i] stores the answer of V[i];
        vector<int> D(N);
        D[N - 1] = -1;
        for(int i = N - 2 ; i >= 0 ; --i){
            int start = V[i].I.start;
            int end = V[i].I.end;
            //find the first interval that has a start >= cnt.end
            if(V[N - 1].I.start < end){
                D[i] = -1;
                continue;
            }
            int L = i + 1, R = N - 1;
            while(L ^ R){//[L,R] first *.start >= end
                int M = (L + R) >> 1;
                if(V[M].I.start >= end)
                    R = M;
                else
                    L = M + 1;
            }
            D[i] = V[L].id;
        }
        
        //reorder answers from D
        vector<int> ret(N);
        for(int i = 0 ; i < N ; ++i){
            ret[V[i].id] = D[i];
        }
        return ret;
    }
    void Test(){
        
    }
};

int main(){
    Solution S;
    S.Test();
	return 0;
}
