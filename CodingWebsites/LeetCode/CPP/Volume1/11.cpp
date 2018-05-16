#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    int n;
    vector<int> ST;
    struct A{
        int id,a;
        A(){}
        A(int id,int a):id(id),a(a){}
        bool operator < (const A & B)const{
            return a < B.a;
        }
    };
    vector<A> Rank;
public:
    int maxArea(vector<int>& height) {
        n = height.size();
        //Sort By Height
        Rank = vector<A>(n);
        for(int i = 0 ; i < n ; ++i) Rank[i] = A(i+1,height[i]);
        sort(Rank.begin(),Rank.end());
        //for(int i = 0 ; i < n ; ++i){
         //   printf("Rank[%d] = (%d,%d)\n",i,Rank[i].id,Rank[i].a);
        //}
        
        //Solve By Segment Tree
        ST_Init();
        ST_Build(1,n,1);
        //printf("Build Done\n");
        int Max = 0;
        for(int i = 0 ; i < n ; ++i){
            //printf("i=%d\n",i);
            //Record Answer
            int LeftMost = ST_QueryLeft(1,n,1);
            //printf("Left Done\n");
            int RightMost = ST_QueryRight(1,n,1);
            //printf("id = %d (L,R) = (%d,%d)\n",Rank[i].id,LeftMost,RightMost);
            int CurMax = Rank[i].a * max(Rank[i].id - LeftMost,RightMost - Rank[i].id);
            //printf("CurMax = %d\n",CurMax);
            Max = max(Max,CurMax);
            
            //Delete Number
            ST_Update(Rank[i].id,1,n,1);
        }
        ST_Clear();
        return Max;
    }
    void ST_Init(){
        ST = vector<int>(n << 2);
    }
    void ST_Build(int l,int r,int rt){
        if(l == r){
            ST[rt] = 1;
            return;
        }
        int m = (l + r) >> 1;
        ST_Build(l,m,rt << 1);
        ST_Build(m + 1 , r , rt << 1 | 1);
        ST[rt] = ST[rt << 1] + ST[rt << 1 | 1];
    }
    void ST_Update(int X,int l,int r,int rt){
        if(l == r){
            ST[rt] --;
            return;
        }
        int m = (l + r) >> 1;
        if(X <= m) ST_Update(X,l,m,rt << 1);
        else ST_Update(X,m + 1, r, rt << 1 | 1);
        ST[rt]--;
    }
    int ST_QueryLeft(int l,int r,int rt){
        //query the position of the leftmost 1
        if(l == r) return l;
        int m = (l + r) >> 1;
        if(ST[rt << 1] > 0) return ST_QueryLeft(l,m,rt << 1);
        else return ST_QueryLeft(m + 1, r, rt << 1 | 1);
    }
    int ST_QueryRight(int l,int r,int rt){
        //query the position of the rightmost 1
        if(l == r) return l;
        int m = (l + r) >> 1;
        if(ST[rt << 1 | 1] > 0) return ST_QueryRight(m + 1, r, rt << 1 | 1);
        else return ST_QueryRight(l, m, rt << 1);
    }
    void ST_Clear(){
        ST.clear();
    }
    void Test(){
        vector<int> V;
        V.push_back(1);
        V.push_back(2);
        V.push_back(4);
        V.push_back(3);
        cout<<maxArea(V)<<endl;
    }
};


int main(){
    Solution S;
    S.Test();
	return 0;
}
