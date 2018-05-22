#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int T,N,A[1001];
int main(){
    freopen("P1020.txt","r",stdin);
    scanf("%d",&T);
    
    for(int C=1;C<=T;++C){
        scanf("%d",&N);
        for(int i=0;i<N;++i) scanf("%d",&A[i]);
        for(int i=N;--i;A[i]-=A[i-1]);
        sort(A,A+N);
        printf("Case %d:\n",C);
        for(int i=0;i<N;++i){
            printf("%d",A[i]);
            printf("%s",i+1==N?"\n\n":" ");
        }
    }
    return 0;
}


