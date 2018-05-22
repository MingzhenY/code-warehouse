#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
int Rank[80007],Rn;
void SetRank(){
    sort(Rank+1,Rank+1+Rn);
    int I = 1;
    for(int i = 2 ; i <= Rn ; ++i){
        if(Rank[i] != Rank[i - 1]) Rank[++I] = Rank[i];
    }
    Rn = I;
}
int GetRank(int v){
    int L = 1 , R = Rn + 1 , M ;//[L,R) last <= v
    while((L + 1) ^ R){
        M = (L + R) >> 1;
        if(Rank[M] <= v) L = M;
        else R = M;
    }
    return L;
}
int Max[262144],N;
void Build(){
    N = 1 ;
    while(N < Rn + 2) N <<= 1;
    memset(Max,0,sizeof(Max));
}
void Update(int L,int R,int M){
    for(int s = N + L - 1 , t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1 , t >>= 1){
        if(~s & 1) Max[s ^ 1] = max(Max[s ^ 1],M);
        if( t & 1) Max[t ^ 1] = max(Max[t ^ 1],M);
    }
}
void PushDownAll(){
    for(int i = 1 ; i < N ; ++i){
        if(Max[i]){
            int L = i << 1 , R = L | 1;
            Max[L] = max(Max[L],Max[i]);
            Max[R] = max(Max[R],Max[i]);
        }
    }
}
int A[40007],B[40007],H[40007];
int main(){
    freopen("P1224.txt","r",stdin);
    int T,Ai,Bi,Hi;
    while(~scanf("%d",&T)){
        Rn = 0;
        for(int i = 0 ; i < T ; ++i){
            scanf("%d%d%d",&A[i],&B[i],&H[i]);
            Rank[++Rn] = A[i];
            Rank[++Rn] = B[i];
        }
        SetRank();
        Build();
        for(int i = 0 ; i < T ; ++i)
            Update(GetRank(A[i]),GetRank(B[i])-1,H[i]);
        PushDownAll();
        LL ANS = 0 , PreH = 0;
        for(int i = 1 , j = N + 1; i < N ; ++i , ++j){
            ANS += (LL)(Rank[i] - Rank[i - 1]) * PreH;
            PreH = Max[j];
        }
        printf("%lld\n",ANS);
    }
    return 0;
}


