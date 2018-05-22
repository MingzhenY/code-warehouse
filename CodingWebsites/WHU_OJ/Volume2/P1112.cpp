#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
//离散化
int Rank[10001],Rn;
void SetRank(){
    sort(Rank,Rank+Rn);
    int I=1;
    for(int i=1;i<Rn;++i)
        if(Rank[i]!=Rank[i-1])
            Rank[I++]=Rank[i];
    Rn=I;
}
int GetRank(int v){
    int L=0,R=Rn,M;//[L,R) last <= v
    while(L+1<R){
        M=(L+R)>>1;
        if(Rank[M] <= v) L=M;
        else R=M;
    }
    return L;
}
//并查集
int F[10001],R[10001];
int Find(int x){
    if(x==F[x]) return x;
    int t=Find(F[x]);
    R[x]^=R[F[x]];
    return F[x]=t;
}
void Union(int x,int y,int r){
    int Fx=Find(x),Fy=Find(y);
    F[Fx]=Fy;
    R[Fx]=r^R[x]^R[y];
}
//题目数据
int Len,M;
int A[5001],B[5001],V[5001];
char str[8];
int main(){
    freopen("P1112.txt","r",stdin);
    while(~scanf("%d%d",&Len,&M)){
        Rn=0;
        for(int i=0;i<M;++i){
            scanf("%d%d%s",&A[i],&B[i],str);
            V[i]=str[0]=='o';//1:odd
            Rank[Rn++]=A[i];
            Rank[Rn++]=++B[i];
        }
        SetRank();
        for(int i=0;i<Rn;++i) F[i]=i,R[i]=0;
        int ANS=0;
        for(int i=0;i<M;++i){
            A[i]=GetRank(A[i]);
            B[i]=GetRank(B[i]);
            if(Find(A[i])!=Find(B[i])) Union(A[i],B[i],V[i]);
            else {
                if((R[A[i]]^R[B[i]])!=V[i]) break;
            }
            ++ANS;
        }
        printf("%d\n",ANS);
    }
    return 0;
}


