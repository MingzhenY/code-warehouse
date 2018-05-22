/*
 二分法或双指针
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int A[100000],N,S;
int Sum[100000];
bool T(int L){//Is length L able to reach S
    int Ans = Sum[L - 1];
    for(int i = 0 , j = L ; j <= N ;){
        Ans += A[j++] - A[i++];
        if(Ans >= S) return true;
    }
    return false;
}
int BS(){//Binary Search
    int L=1,R=N,M;//[L,R] find first that fits
    while(L ^ R){
        M = (L + R) >> 1 ;
        if(T(M)) R = M;
        else L = M + 1;
    }
    return L;
}

int main(){
    freopen("P1301.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d%d",&N,&S);
        for(int i=1;i<=N;++i) {
            scanf("%d",&A[i]);
            Sum[i] = Sum[i - 1] + A[i];
        }
        printf("%d\n",Sum[N] >= S ? BS() : 0);
    }
    return 0;
}


