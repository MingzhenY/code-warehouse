#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 50000
#define LL long long
using namespace std;

int u[maxn+7];
bool prime[maxn+7];
void Init(){
    for(int i=1;i<=maxn;++i) u[i] = 1;
    memset(prime,-1,sizeof(prime));
    
    for(int i=2;i<=maxn;++i){
        if(!prime[i]) continue;
        for(int j = 1 , J = i ; J <= maxn ; ++ j , J += i) {
            prime[J] = false;
            u[J] = j % i ? - u[J]
                         : 0;
        }
    }
}
LL F(LL m,LL n,LL k){
    return (m/k)*(n/k);
}
LL G(int m,int n){
    LL ANS = 0;
    for(int i = 1 ; i <= maxn ; ++i){
        if(u[i]) ANS += u[i] * F(m,n,i);
    }
    return ANS;
}
int main(){
    freopen("P1420.txt","r",stdin);
    
    Init();
    int t,m,n;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&m,&n);
        cout<<G(m,n)<<endl;
    }
    return 0;
}


