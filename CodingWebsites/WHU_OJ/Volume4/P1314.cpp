#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
LL A[1000007];
LL F(LL i){
    if(i <= 1000000){
        if(~A[i]) return A[i];
        if(i & 1) return A[i] = F(3 * i + 1) + 1;
        else return A[i] = F(i >> 1) + 1;
    }
    else{
        if(i & 1) return F(3 * i + 1) + 1;
        else return F(i >> 1) + 1;
    }
}
void Init(){
    memset(A,-1,sizeof(A));
    A[1] = 1;
    for(int i = 2 ; i <= 1000000 ; ++i) F(i);
}
int main(){
    freopen("P1314.txt","r",stdin);
    Init();
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        if(a == 0 && b == 0) break;
        LL Max = 0;
        for(int i = a ; i <= b ; ++i) Max = max(Max,A[i]);
        printf("%lld\n",Max);
    }
    return 0;
}


