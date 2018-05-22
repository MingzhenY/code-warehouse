#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 100007
#define LL long long
using namespace std;

int N;
LL Max[maxn<<2],Min[maxn<<2];
LL AMax,AMin;
void Build(int n){
    N=1;
    while(N < n + 2) N <<= 1;
    for(int i=1;i<=n;++i) {
        scanf("%lld",&Max[N+i]);
        Min[N+i]=Max[N+i];
    }
    for(int i=N-1;i>=1;--i){
        Max[i]=max(Max[i<<1],Max[i<<1|1]);
        Min[i]=min(Min[i<<1],Min[i<<1|1]);
    }
}
void Update(int x,LL v){
    Max[N+x]=Min[N+x]=v;
    for(int i=N+x;i>1;i>>=1)
        Max[i>>1]=max(Max[i],Max[i^1]),
        Min[i>>1]=min(Min[i],Min[i^1]);
}

void Query(int L,int R){
    for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
        if(~s&1) {
            AMax=max(AMax,Max[s^1]);
            AMin=min(AMin,Min[s^1]);
        }
        if( t&1) {
            AMax=max(AMax,Max[t^1]);
            AMin=min(AMin,Min[t^1]);
        }
    }
}
int T,n,q;
int main(){
    freopen("P1344.txt","r",stdin);
    scanf("%d",&T);
    while(T-->0){
        scanf("%d%d",&n,&q);
        Build(n);
        for(int i=0;i<q;++i){
            char ch;
            LL a,b;
            scanf(" %c%lld%lld",&ch,&a,&b);
            if(ch=='C') Update(a,b);
            else {
                AMax=AMin=Max[N+a];
                Query(a,b);
                printf("%lld\n",AMax-AMin);
            }
        }
    }
    return 0;
}


