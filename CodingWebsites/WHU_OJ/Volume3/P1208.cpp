#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#define LL long long
using namespace std;
int A[50007],B[50007],N,C[50007],Cn;
int BunderX(int X){//Count number of B that are <= X
    int L = 0 , R = N , M ; //[L,R) last <= X
    if(X < B[0]) return 0;
    while((L + 1) ^ R){
        M = (L + R) >> 1;
        if(B[M] <= X) L = M;
        else R = M;
    }
    return L + 1;
}
bool IsEnough(int X){//are there at least N pairs that A + B <= X
    int Count = 0;
    for(int i = 0 ; i < N && A[i] + B[0] <= X; ++i){
        Count += BunderX(X - A[i]);
        if(Count >= N) return true;
    }
    return false;
}
int BinarySearch(){//find the max of A + B
    int L = 0 , R = 1 << 17 , M , C;//[L,R]
    while(L ^ R){
        M = (L + R) >> 1;
        if(IsEnough(M)) R = M;
        else L = M + 1;
    }
    return L;
}
void GetAnswer(int X){
    Cn = 0;
    for(int i = 0 ; i < N && A[i] + B[0] < X ; ++i){
        for(int j = 0 ; j < N && A[i] + B[j] < X ; ++j){
            C[Cn++] = A[i] + B[j];
            if(Cn >= N) return;
        }
    }
    while(Cn < N) C[Cn++] = X ;
}
int main(){
    freopen("P1208.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i = 0 ; i < N ; ++i) scanf("%d",&A[i]);
        for(int i = 0 ; i < N ; ++i) scanf("%d",&B[i]);
        sort(A,A+N);
        sort(B,B+N);
        GetAnswer(BinarySearch());
        sort(C,C+Cn);
        for(int i = 0 ; i < Cn ; ++i) printf("%d ",C[i]);
        printf("\n");
    }
    return 0;
}
