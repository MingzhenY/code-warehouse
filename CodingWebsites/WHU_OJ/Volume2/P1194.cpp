#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool V[11];
int A[11];
char str[11][16];
int C[11][11];
int Calculate(char *s1,char *s2){
    int L1 = strlen(s1);
    int L2 = strlen(s2);
    //s1[i] match s2[i+k]
    //k <- [-(L1-1),-2,-1,0,1,2,...,L2-1]
    int ANS = 0;
    for(int k = -(L1 - 1) ; k < L2 ; ++k){
        int D = 0;
        for(int i = 0 ; i < L1 ; ++i){
            if(i + k >= 0 && i + k < L2 && s1[i] == s2[i + k]) ++D;
        }
        if(D > ANS) ANS = D;
    }
    return ANS;
}
int ANS;
void F(int k,int n){
    if(k == n){/*
        for(int i = 0 ; i < n ; ++i) printf("%d ",A[i]);
        printf("\n");*/
        int D = 0;
        for(int i = 1 ; i < n ; ++i) D += C[A[i]][A[i-1]];
        if(D > ANS) {
            ANS = D;/*
            printf("D = %d:  ",D);
            for(int i = 0 ; i < n ; ++i) printf("%d ",A[i]);
            printf("\n");*/
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(V[i]) continue;
        A[k] = i;
        V[i] = true;
        F(k+1,n);
        V[i] = false;
    }
}
int main(){
    freopen("P1194.txt","r",stdin);
    int N;
    while(~scanf("%d",&N) && N){
        for(int i = 1 ; i <= N ; ++i) scanf("%s",str[i]);
        for(int i = 1 ; i <= N ; ++i){
            for(int j = i + 1 ; j <= N ; ++j){
                C[j][i] = C[i][j] = Calculate(str[i],str[j]);
            }
        }
        ANS = 0;
        F(0,N);
        printf("%d\n",ANS);
    }
    return 0;
}


