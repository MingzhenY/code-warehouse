#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;


int n;
int main(){
    freopen("P1058.txt","r",stdin);
    while(~scanf("%d",&n)&&n){
        LL tEven=n/2,tOdd=(n-1)/2-1;
        LL dEven=tEven/3,dOdd=tOdd/3;
        LL ANS=n+3*dEven*(dEven-1)/2+dEven*(tEven-3*dEven+1);
        if(n>=3) ANS+=3*dOdd*(dOdd-1)/2+dOdd*(tOdd-3*dOdd+1);
        printf("%lld\n",ANS);
    }
    return 0;
}


