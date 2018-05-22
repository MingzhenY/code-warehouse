#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int T,N,A[3000];
int main(){
    freopen("P1046.txt","r",stdin);
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d",&N);
        for(int i=0;i<N;++i) scanf("%d",&A[i]);
        int ANS=0;
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j)
                ANS+=A[i]>A[j];
        printf("%d\n",ANS);
    }
    return 0;
}


