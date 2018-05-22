#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int A[10000],A2[10000],N,T;
bool Find(int v){
    int L = 0 , R = N - 1 , M ;//[L,R]
    while(L ^ R){//First >= v
        M = (L + R) >> 1;
        if(A[M] >= v) R = M;
        else L = M + 1;
    }
    return A[L] == v;
}
int main(){
    freopen("P1074.txt","r",stdin);
    scanf("%d",&T);
    while(T-->0){
        int i,j;
        scanf("%d",&N);
        for(i = 0 ; i < N ; ++i) scanf("%d",&A[i]);
        sort(A,A + N);
        for(i = 0 ; i < N ; ++i) A2[i] = A[i] << 1 ;
        bool Found = false;
        for(i = N - 1 ; i > 0 ; --i){
            for(j = 0 ; A2[j] < A[i] ; ++j){
                if(Find(A[i]-A[j])){
                    Found = true;
                    printf("%d\n",A[i]);
                    break;
                }
            }
            if(Found) break;
            if(A2[j] == A[i] && A[j] == A[j+1]){
                Found = true;
                printf("%d\n",A[i]);
                break;
            }
        }
        if(!Found) printf("-1\n");
    }
    return 0;
}


