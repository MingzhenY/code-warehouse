#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
int maxprime[10101];
int prime[10001],pn;
LL prime2[10001];
void Init(){
    memset(maxprime,-1,sizeof(maxprime));
    pn = 0;
    for(int i = 2 ; i <= 10100 ; ++i){
        if(~maxprime[i]) continue;
        prime[pn++]=i;
        for(int j = i ; j <= 10100 ; j += i) maxprime[j] = i;
    }
    for(int i=0;i<pn;++i) prime2[i]=(LL)prime[i]*prime[i];
}
int DigitSum(int v){
    int Sum = 0;
    while(v){
        Sum += v%10;
        v/=10;
    }
    return Sum;
}
int PrimeDigitSum(int v){
    int Sum = 0;
    for(int i = 0 ; prime2[i] <= v ; ++i){
        int P = prime[i];
        while(v % P == 0){
            Sum += DigitSum(P);
            v /= P;
        }
    }
    if(v > 1) Sum += DigitSum(v);
    return Sum;
}
bool isPrime(int v){
    for(int i = 0 ; prime2[i] <= v ; ++i){
        if(v % prime[i] == 0) return false;
    }
    return v!=1;
}

int main(){
    freopen("P1165.txt","r",stdin);
    Init();
    int N;
    while(~scanf("%d",&N)&&N){
        printf("%s\n",!isPrime(N)&&DigitSum(N)==PrimeDigitSum(N)?"Yes":"No");
    }
    return 0;
}


