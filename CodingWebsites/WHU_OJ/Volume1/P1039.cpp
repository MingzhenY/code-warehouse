#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int N,P[100001],A[200001];

//带权并查集
int F[200001],V[200001];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
void Union(int x,int y){F[Find(x)]=Find(y);}

int main(){
    freopen("P1039.txt","r",stdin);
    while(~scanf("%d",&N)&&N){
        
        for(int i=1;i<=N;++i) scanf("%d",&P[i]);
        for(int i=1;i<=200000;++i) A[F[i]=V[i]=i]=0;
        
        for(int i=1;i<=N;++i){
            int Loc=Find(P[i]);
            A[Loc]=i;
            Union(Loc,Loc+1);
        }
        int Max=200000;
        while(!A[Max]) --Max;
        printf("%d\n%d",Max,A[1]);
        for(int i=2;i<=Max;++i)
            printf(" %d",A[i]);
        printf("\n");
    }
    return 0;
}


