#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

void F(LL a,LL b){
    int L,A[4];
    L=a/b;
    for(int i=0;i<4;++i){
        a%=b;
        a*=10;
        A[i]=a/b;
    }
    if(A[3]>=5) ++A[2];
    
    if(A[2]>=10){
        A[1]+=A[2]/10;
        A[2]%=10;
    }
    
    if(A[1]>=10){
        A[0]+=A[1]/10;
        A[1]%=10;
    }
    
    if(A[0]>=10){
        L+=A[0]/10;
        A[0]%=10;
    }
    printf("%d.%d%d%d\n",L,A[0],A[1],A[2]);
}
int main(){
    freopen("P1062.txt","r",stdin);
    int T;
    LL a,b,c,u,v,p,d;
    cin>>T;
    while(T--){
        cin>>a>>u>>b>>v>>c>>p>>d;
        d>0?F(c*u+c*v-a*v-a*p+b*p-b*u,2*v+2*u):F(b*p+b*u-a*p+a*v-c*v-c*u,2*v+2*u);
    }
    return 0;
}


