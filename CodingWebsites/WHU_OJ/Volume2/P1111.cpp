#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int Input(){//100000.00
    char str[16];
    scanf("%s",str);
    int ANS=0;
    for(char *p=str;*p;++p){
        ANS*=*p!='.'?10:1;
        ANS+=*p!='.'?*p-'0':0;
    }
    return ANS;
}
int N,K,A[10000];
int F(int L){
    int ANS=0;
    for(int i=0;i<N;++i) ANS+=A[i]/L;
    return ANS;
}
int main(){
    freopen("P1111.txt","r",stdin);
    while(~scanf("%d%d",&N,&K)&&N&&K){
        for(int i=0;i<N;++i) A[i]=Input();
        int L=0,R=10000001,M;//[L,R) last >= K
        while(L+1!=R){
            M=(L+R)>>1;
            if(F(M)>=K) L=M;
            else R=M;
        }
        printf("%d.%02d\n",L/100,L%100);
    }
    return 0;
}


