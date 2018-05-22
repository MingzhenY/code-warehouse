#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int Value[100007],Count[100007],Sum[100007];
int Rn,Qn,Vn,v;
int GetI(int k){
    int L = 1 , R = Vn , M ;//First I that Sum[I] >= k
    while(L ^ R){//[L,R]
        M = (L + R) >> 1;
        if(Sum[M] >= k) R = M;
        else L = M + 1;
    }
    return L;
}
int MaxSum[262144],N;
void Build(){
    N = 1;
    while(N <= Vn + 2) N <<= 1;
    MaxSum[N] = 0;
    for(int i = 1 ; i <= Vn ; ++i) MaxSum[N + i] = Count[i];
    for(int i = Vn + 1 ; i < N ; ++i) MaxSum[N + i] = 0;
    for(int i = N - 1 ; i ; --i)
        MaxSum[i] = max(MaxSum[i << 1] , MaxSum[i << 1 | 1]);
}
int Query(int L,int R){
    int ANS = 0;
    for(int s = N + L - 1 , t = N + R + 1 ; s ^ t ^ 1 ; s >>= 1 , t >>= 1){
        if(~s & 1) ANS = max(ANS,MaxSum[s ^ 1]);
        if( t & 1) ANS = max(ANS,MaxSum[t ^ 1]);
    }
    return ANS;
}
int main(){
    freopen("P1281.txt","r",stdin);
    while(~scanf("%d",&Rn) && Rn){
        scanf("%d",&Qn);
        Count[Vn = 0] = 1 << 30;
        for(int i = 1 ; i <= Rn ; ++i){
            scanf("%d",&v);
            if(v == Value[Vn]) ++Count[Vn];
            else Value[++Vn] = v , Count[Vn] = 1;
        }
        Sum[0] = 0;
        for(int i = 1 ; i <= Vn ; ++i) Sum[i] = Sum[i - 1] + Count[i];
        Build();
        for(int i = 1 ; i <= Qn ; ++i){
            int L,R,ANS,LI,RI;
            scanf("%d%d",&L,&R);
            LI = GetI(L);
            RI = GetI(R);
            ANS = LI == RI ? R - L + 1 :
                  LI + 1 == RI ? max(Sum[LI] - L + 1 , R - Sum[RI - 1]) :
                  max(Query(LI + 1,RI - 1),max(Sum[LI] - L + 1 , R - Sum[RI - 1]));
            printf("%d\n",ANS);
        }
    }
    return 0;
}


