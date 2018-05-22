#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 100000
#define MOD 1000000007
#define LL long long
using namespace std;
int maxprime[maxn+1];
int Prime[maxn/10+1],PrimeN;
LL Prime2[maxn/10+1];
void Init(){
    memset(maxprime,-1,sizeof(maxprime));
    PrimeN = 0;
    for(int i=2;i<=maxn;++i){
        if(~maxprime[i]) continue;
        Prime[++PrimeN] = i;
        Prime2[PrimeN] = Prime[PrimeN] * Prime[PrimeN];
        for(int j=i;j<=maxn;j+=i) maxprime[j]=i;
    }
}
//质因数分解
int P[32],Pn;
void BreakPrime(LL n){
    Pn = 0;
    if(n <= maxn){
        small:
        while(n>1){
            P[++Pn] = maxprime[n];
            while(n % P[Pn] == 0) n/=P[Pn];
        }
    }
    else{
        for(LL i = 1 ; Prime2[i] <= n ; ++i){
            if(n % Prime[i]){
                P[++Pn]=Prime[i];
                while(n % P[Pn] == 0) n/=P[Pn];
            }
            if(n <= maxn) goto small;
        }
    }
    if(n>1) P[++Pn] = n;
    //for(int i=0;i<Pn;++i) printf("%d^%d ",P[i],N[i]); printf("\n");
}
LL PI(LL n){
    BreakPrime(n);
    LL ANS = n;
    for(int i=1;i<=Pn;++i) ANS = ANS / P[i] * (P[i]-1);
    return ANS;
}
//猜测结论： 答案 = PI(x1) * PI(x2) * ... * PI(xn)
int main(){
    freopen("P1405.txt","r",stdin);
    Init();
    int n,a;
    while(~scanf("%d",&n)){
        LL ANS = 1;
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            ANS = ANS * PI(a) % MOD;
        }
        printf("%d\n",int(ANS));
    }
    return 0;
}


