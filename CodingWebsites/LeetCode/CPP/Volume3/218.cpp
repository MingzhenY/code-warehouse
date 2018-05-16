#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
/*
 1. Using sweepline, scan x-axis
 Will implement later
 
 2. Use non-recursive segment tree
 As shown below
 */
class Solution {
private:
    //Part One: map x coordinates to natural numbers and vise versa
    int Rn;
    vector<int> Rank;
    void setRank(){
        int Kn = Rank.size();
        sort(Rank.begin(),Rank.end());
        Rn = 1;
        for(int i = 1 ; i < Kn ; i++){
            if(Rank[i] != Rank[i - 1])
                Rank[Rn++] = Rank[i];
        }
    }
    int getRank(int V){
        int L = 0 , R = Rn, M;//[L,R)
        while(L + 1 < R){//find last <= V
            M = (L + R) >> 1;
            if(Rank[M] > V) R = M;
            else L = M;
        }
        return L + 1;//the output ranges [1, Rn]
    }
    //Part Two: Non-recursive Segment Tree
    int N;
    vector<int> ST;
    void Init(){
        //Build a non-recursive segment tree
        N = 1;
        while(N < Rn + 2) N <<= 1;
        ST = vector<int>(N << 1,0);
    }
    void Update(int L,int R,int H){
        for(int s = N + L - 1, t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1 , t >>= 1){
            if(~s&1) ST[s ^ 1] = max(ST[s ^ 1], H);
            if( t&1) ST[t ^ 1] = max(ST[t ^ 1], H);
        }
    }
    //Push the heights to leafs
    void PushDown(){
        for(int i = 1 ; i < N ; i++){
            if(ST[i]){
                ST[i << 1] = max(ST[i << 1], ST[i]);
                ST[i << 1 | 1] = max(ST[i << 1 | 1], ST[i]);
            }
        }
    }
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        //Part One: map x coordinates to natural numbers and vise versa
        Rank = vector<int>();
        for(auto x:buildings){
            Rank.push_back(x[0]);//[left,right)
            Rank.push_back(x[1]);
        }
        setRank();
        //Part Two: non-recursive Segment Tree
        Init();
        for(auto x:buildings)
            Update(getRank(x[0]), getRank(x[1]) - 1, x[2]);
        //Push the heights to leafs
        PushDown();
        vector<pair<int, int>> ANS;
        //Part Three: Record answer
        int PrevHeight = 0;
        for(int i = 1 ; i <= Rn ; i++){
            if(ST[N + i] != PrevHeight)
                ANS.push_back(make_pair(Rank[i - 1],ST[N + i]));
            PrevHeight = ST[N + i];
        }
        return ANS;
    }
    void Test(){
        vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
        vector<pair<int, int>> ANS = getSkyline(buildings);
        for(auto x:ANS){
            cout<<"("<<x.first<<","<<x.second<<")"<<endl;
        }
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
