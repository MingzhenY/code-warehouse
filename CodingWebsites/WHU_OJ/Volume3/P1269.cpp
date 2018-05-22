#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int D[50001],A[50001];
void Init(){
    D[0]=0;
    for(int i=1;i<=50000;++i){
        D[i] = D[i - 1] + i - 1;
    }
}
int Sum[131072],N;
void Build(int n){
    N = 1;
    while(N <= n + 2) N <<= 1;
    for(int i = 0 , j = N ; i < N ; ++i , ++j) Sum[j] = i && i <= n;
    for(int i = N - 1 ; i ; --i) Sum[i] = Sum[i << 1] + Sum[i << 1 | 1];
}
int Update(int X,int l,int r,int rt){
    --Sum[rt];
    if(l == r) return rt - N;
    int m = (l + r) >> 1;
    if(Sum[rt << 1] >= X) return Update(X,l,m,rt << 1);
    else return Update(X - Sum[rt << 1],m+1,r,rt << 1 | 1);
}
int main(){
    freopen("P1269.txt","r",stdin);
    int n,m;
    Init();
    while(~scanf("%d%d",&n,&m)&&~n&&~m){
        for(int i = 1 ; i <= n ; ++i){
            if(m > D[n - i]){
                A[i] = m - D[n - i] + 1;
                m = D[n - i];
            }
            else A[i] = 1;
        }
        Build(n);
        for(int i = 1 ; i <= n ; ++i){
            printf("%d%c",Update(A[i],1,N,1),i ^ n ? ' ' : '\n');
        }
    }
    return 0;
}


