#include <iostream>
#include <cstdio>
#include <cstdlib>
#define OUT3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<endl;
using namespace std;
int C,T,L,N,t;
int Pos[1000001],Dir[1000001];
int main(){
    freopen("P1000.txt","r",stdin);
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d%d%d",&L,&N,&t);
        for(int i=1;i<=N;++i)
            scanf("%d%d",&Pos[i],&Dir[i]);
        
    }
    
    
    return 0;
}


