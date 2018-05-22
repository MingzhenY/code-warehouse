#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
LL Fx[2][10][2001];
LL F(int t,int k,int sum){
    if(~Fx[t][k][sum]) return Fx[t][k][sum];
    if(!k) return Fx[t][k][sum] = sum + 1 - t;
    int A = sum >> k ;
    LL ANS = 0;
    for(int i  = t ; i <= A ; ++i)
        ANS += F(0,k - 1,sum - (i << k));
    return Fx[t][k][sum] = ANS;
}
int main(){
    freopen("P1116.txt","r",stdin);
    memset(Fx,-1,sizeof(Fx));
    int T,n,m;
    scanf("%d",&T);
    for(int Case = 1 ; Case <= T ; ++Case){
        scanf("%d%d",&n,&m);
        LL ANS = F(1,n - 1,m);
        printf("Data set %d: %d %d %lld\n",Case,n,m,ANS);
    }
    return 0;
}


