#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int qPow(int a,int k,int m){
    int ANS = 1;
    while(k){
        if(k & 1) ANS = ANS * a % m;
        a = a * a % m;
        k >>= 1;
    }
    return ANS;
}
int main(){
    freopen("P1302.txt","r",stdin);
    int Z,M,H,a,k;
    scanf("%d",&Z);
    while(Z-- > 0){
        scanf("%d%d",&M,&H);
        int ANS = 0;
        for(int i = 0 ; i < H ; ++i){
            scanf("%d%d",&a,&k);
            ANS = (ANS + qPow(a % M,k,M)) % M;
        }
        printf("%d\n",ANS);
    }
    return 0;
}


