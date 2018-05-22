#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int A[5000000],N,K;
int B[5000000],C[5000000],Bn,Cn;
void mergesort(int L,int R){
    if(L == R) return;
    int M = (L + R) >> 1;
    mergesort(L,M);
    mergesort(M+1,R);
    Bn = M - L + 1 ;
    Cn = R - M ;
    for(int i = 0 ; i < Bn ; ++i) B[i] = A[L + i];
    for(int i = 0 ; i < Cn ; ++i) C[i] = A[M + i + 1];
    int Bi = 0 , Ci = 0 , Ai = 0;
    while(Bi < Bn && Ci < Cn){
        if(B[Bi] < C[Ci]) A[L+Ai++]=B[Bi++];
        else A[L+Ai++]=C[Ci++];
    }
    while(Bi < Bn) A[L+Ai++]=B[Bi++];
    while(Ci < Cn) A[L+Ai++]=C[Ci++];
}
int main(){
    freopen("P1152.txt","r",stdin);
    while(~scanf("%d%d",&N,&K)){
        for(int i=1;i<=N;++i) scanf("%d",&A[i]);
        mergesort(1,N);
        printf("%d\n",A[K]);
    }
    return 0;
}


