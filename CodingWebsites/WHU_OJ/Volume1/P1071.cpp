/*
 2016.12.30: 
 Using Segment Tree to solve Joseph Problem.
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N,Sum[65536];
void Init(int n){
    N = 1;
    while(N <= n + 2) N <<= 1;
    for(int i = 0 , j = N ; i < N ; ++i , ++j) Sum[j] = i && i <= n;
    for(int i = N - 1 ; i ; --i) Sum[i] = Sum[i << 1] + Sum[i << 1 | 1];
}

void Update(int X,int l,int r,int rt){
    --Sum[rt];
    if(l == r){
        printf("%d ",rt - N);
        return;
    }
    int m = (l + r) >> 1;
    if(Sum[rt << 1] >= X) Update(X,l,m,rt << 1);
    else Update(X - Sum[rt << 1],m + 1,r,rt << 1 | 1);
}
int main(){
    freopen("P1071.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        Init(n);
        int Cur = 1 , Left = n ;
        while(Left){
            Cur = (Cur + m - 2) % Left-- + 1;
            Update(Cur,1,N,1);
        }
        printf("\n");
    }
    return 0;
}


