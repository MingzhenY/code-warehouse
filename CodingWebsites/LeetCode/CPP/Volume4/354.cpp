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

/*
Solution1 : Graph O(n^2) TLE
Solution2 : Sort + Segment Tree AC
Solution3 : Sort + LIS
*/

class Solution1 {
    /*
    Graph Theroy O(n^2) TLE
    */
    vector<list<int>> Arc;
    bool LT(const pair<int,int> &A,const pair<int,int> &B){
        return (A.first < B.first && A.second < B.second);
                //|| (A.first < B.second && A.second < B.first);
    }
    vector<int> D;
    int F(int x){
        if(D[x] != -1)
            return D[x];
        D[x] = 0;
        for(auto to : Arc[x]){
            int temp_D = F(to) + 1;
            if(temp_D > D[x])
                D[x] = temp_D;
        }
        return D[x];
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int N = envelopes.size();
        Arc.resize(N + 2);
        for(int i = 0 ; i < N ; ++i){
            for(int j = i + 1 ; j < N ; ++j){
                if(LT(envelopes[i],envelopes[j])){
                    Arc[i].push_back(j);
                }
                if(LT(envelopes[j],envelopes[i])){
                    Arc[j].push_back(i);
                }
            }
        }
        for(int i = 0 ; i < N ; ++i){
            Arc[N].push_back(i);//N is start point
            Arc[i].push_back(N+1);//N+1 is end point
        }
        Arc[N].push_back(N+1);
        D = vector<int>(N+2,-1);
        D[N+1] = 0;
        return F(N) - 1;
    }
    void Test(){
        vector<pair<int,int>> envelopes = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
        printf("%d\n",maxEnvelopes(envelopes));
    }
};


class Solution {
    /*
    Segment Tree + Sort (AC)
    */
    //Part One: Remove Duplicates and map values to [1..Rn]
    int Rn, N;
    vector<int> Rank;
    vector<int> ST;
    void setRank(){
        Rn = Rank.size();
        if(Rn <= 1) return;
        sort(Rank.begin(),Rank.end());
        int I = 1;
        for(int i = 1 ; i < Rn ; ++i){
            if(Rank[i] != Rank[i - 1])
                Rank[I++] = Rank[i];
        }
        Rn = I;
        
        Rank.resize(Rn);
    }
    int getRank(int v){
        int L = 0, R = Rn;//[L,R)
        while(L + 1 < R){//last <= v
            int M = (L + R) >> 1;
            if(Rank[M] <= v)
                L = M;
            else
                R = M;
        }
        return L + 1;
    }
    //Part Two: Segment Tree
    void Init(){
        N = 1; while(N < Rn + 2) N <<= 1;
        ST = vector<int>(N * 2, 0);
    }
    void Update(int X,int V){
        if(V <= ST[N + X])
            return;
        ST[N + X] = V;
        for(int s = N + X ; s >>= 1 ;){
            ST[s] = max(ST[s << 1], ST[s << 1 | 1]);
        }
    }
    int Query(int L, int R){
        if(L > R) return 0;
        int ANS = 0;
        for(int s = N + L - 1, t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1, t >>= 1){
            if(~s & 1) ANS = max(ANS, ST[s ^ 1]);
            if( t & 1) ANS = max(ANS, ST[t ^ 1]);
        }
        return ANS;
    }
    
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        for(auto x:envelopes)
            Rank.push_back(x.second);
        setRank();
        if(Rn == 0) return 0;
        Init();
        sort(envelopes.begin(),envelopes.end(),greater<pair<int,int>>());
        int cntX = envelopes[0].first, EN = envelopes.size();
        queue<pair<int,int>> Q;
        int ANS = 0;
        for(int i = 0 ; i < EN ; ++i){
            if(envelopes[i].first != cntX){
                //Only Apply Changes when _.first changes
                while(!Q.empty()){
                    pair<int,int> t = Q.front();
                    Q.pop();
                    Update(t.first,t.second);
                }
                cntX = envelopes[i].first;
            }
            int ID = getRank(envelopes[i].second);
            int V = Query(ID+1,Rn) + 1;
            Q.push(make_pair(ID,V));
            if(V > ANS)
                ANS = V;
        }
        return ANS;
    }
    void Test(){
        vector<pair<int,int>> envelopes = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
        printf("%d\n",maxEnvelopes(envelopes));
    }
};
int main(){
    Solution S;
    S.Test();
	return 0;
}
