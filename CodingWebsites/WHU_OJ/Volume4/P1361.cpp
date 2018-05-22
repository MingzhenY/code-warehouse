/*
 WA: 
 */
#include <iostream>
#include <cstdio>  
#include <algorithm> 
#define maxn 100007  
#define maxnn  1860007  
using namespace std;  
int L[maxnn],R[maxnn],Sum[maxnn],T[maxn],TP;
void Add(int &rt,int l,int r,int x){
    ++TP;L[TP]=L[rt];R[TP]=R[rt];Sum[TP]=Sum[rt]+1;rt=TP; 
    if(l==r) return;  
    int m=(l+r)>>1;  
    if(x <= m) Add(L[rt],l,m,x);  
    else       Add(R[rt],m+1,r,x);  
}  
int Search(int TL,int TR,int l,int r,int k){ 
    if(l==r) return l;
    int m=(l+r)>>1;  
    if(Sum[L[TR]]-Sum[L[TL]]>=k) return Search(L[TL],L[TR],l,m,k);  
    else return Search(R[TL],R[TR],m+1,r,k-Sum[L[TR]]+Sum[L[TL]]);  
}  

int n,m;  
int value[maxn];  

int Rank[maxn],Rn;
void SetRank(){
    sort(Rank+1,Rank+Rn+1);
    int I=1;
    for(int i=2;i<=Rn;++i)
        if(Rank[i]!=Rank[i-1]) 
            Rank[++I]=Rank[i];
    Rn=I;
}
int GetRank(int V){
    int L=1,R=Rn+1,M;//[L,R) last <= V
    while(L+1<R){
        M=(L+R)>>1;
        if(Rank[M]<=V) L=M;
        else R=M;
    }
    return L;
}

int main(void)  
{  
    freopen("P1361.txt","r",stdin);
    int Test;scanf("%d",&Test);  
    while(Test-->0){ 
        scanf("%d%d",&n,&m);  
        Rn=0;
        for(int i=1;i<=n;++i) {  
            scanf("%d",&value[i]);  
            Rank[++Rn]=value[i];
        }  
        SetRank();
        L[0]=R[0]=Sum[0]=T[0]=TP=0;  
        for(int i=1;i<=n;++i) Add(T[i]=T[i-1],1,n,GetRank(value[i]));  
        for(int i=0;i<m;++i){  
            int s,t,k;scanf("%d%d%d",&s,&t,&k);  
            printf("%d\n",Rank[Search(T[s-1],T[t],1,n,k)]);
        }  
    }  
return 0;  
}  
