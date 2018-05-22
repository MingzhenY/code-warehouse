#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LL long long
using namespace std;

int main(){
    freopen("P1173.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m){
        /* A method that is TLE
        LL N = n , M = m ;
        LL Max=N*(M-1),A=N*M+1;
        LL T = 1;
        while(T <= Max) T+=1+(T-1)/(m-1);
        printf("%d\n",int(A-T));
         */
        LL A=0;
        for(int i=1;i<=n;++i) A = (A + m) % i;
        printf("%d\n",int(A+1));
    }
    return 0;
}
