#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[64],Len,Neg;
void P1(int N,int R){
    memset(A,0,sizeof(A));
    if(N < 0) Neg = 1 , N = - N ;
    else Neg = 0 ;
    R = - R;
    Len = 0;
    while(N){
        A[Len++] = N % R;
        N /= R;
    }
}
void P2(){
    Len = 63;
    while(!A[Len]) --Len;
    for(int i = Len ; i >= 0 ; --i)
        printf("%c",A[i] < 10 ? A[i] + '0' : A[i] - 10 + 'A');
    printf("\n");
}
void P3(int R){
    R = - R;
    for(int i = 1 ; i < 64 ; i += 2) A[i] = -A[i];
    if(Neg){
        for(int i = 0 ; i < 64 ; ++i) A[i] = -A[i];
    }
    for(int i = 0 ; i < 63 ; i ++){
        if(A[i] < 0){
            A[i] += R;
            ++A[i + 1];
        }
        if(A[i] >= R){
            A[i] -= R;
            --A[i + 1];
        }
    }
}
int main(){
    freopen("P1316.txt","r",stdin);
    int N,R;
    while(~scanf("%d%d",&N,&R)&&(N||R)){
        if(!N){
            printf("0\n");
            continue;
        }
        P1(N,R);
        P3(R);
        P2();
    }
    return 0;
}


