#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int N,a;
int L[10000],R[10000];
int L_[10000];

int main(){
    freopen("P1157.txt","r",stdin);
    int TC=0;
    while(~scanf("%d",&N)&&~N){
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        for(int i=0;i<N;++i){
            scanf("%d",&a);
            if(a==-1) L[i]=1;
            else R[i]=1;
        }
        L_[N-1]=L[N-1];
        for(int i=N-2;i>=0;--i) L_[i]=L[i]+L_[i+1];
        
        int ANS=0;
        for(int i=0;i<N;++i){
            if(R[i]) ANS+=L_[i];
        }
        printf("Case %d: %d\n",++TC,ANS);
    }
    return 0;
}


