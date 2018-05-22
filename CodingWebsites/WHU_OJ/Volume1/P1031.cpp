#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
struct Int{
    LL a[2];
    Int(){}
    Int(int k){
        a[0] = k;
        a[1] = 0;
    }
    Int operator +(Int B){
        Int C;
        C.a[0] = a[0] + B.a[0];
        C.a[1] = a[1] + B.a[1];
        if(C.a[0] >= 1000000000000LL){
            ++C.a[1];
            C.a[0] -= 1000000000000LL;
        }
        return C;
    }
    void Show(){
        if(a[1]) printf("%lld%012lld\n",a[1],a[0]);
        else printf("%lld\n",a[0]);
    }
};
int N,M,K;
Int FX[101][501];
bool Vis[101][501];
Int F(int n,int sum){
    if(Vis[n][sum]) return FX[n][sum];
    Vis[n][sum] = true;
    if(!n) return FX[n][sum] = Int(sum == 0 ? 1 : 0);
    Int ANS(0);
    for(int i = 0 , S = sum ; i <= K && S >= 0; ++i , S -= n){
        ANS = ANS + F(n - 1,S);
    }
    return FX[n][sum] = ANS;
}
int main(){
    freopen("P1031.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&M,&K)&&N&&M&&K){
        memset(Vis,0,sizeof(Vis));
        F(M,N).Show();
    }
    return 0;
}


