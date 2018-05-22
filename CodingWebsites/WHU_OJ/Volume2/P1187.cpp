#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool DP[100][10000];
int N,A[100],M;
int main(){
    freopen("P1187.txt","r",stdin);
    while(~scanf("%d",&N)){
        M = 0;
        for(int i = 1 ; i <= N ; ++i) scanf("%d",&A[i]) , M += A[i];
        memset(DP,0,sizeof(DP));
        DP[0][0] = true;
        for(int i = 1 ; i <= N ; ++i){
            for(int j = 0 ; j <= M ; ++j) DP[i][j] = DP[i-1][j];
            for(int j = A[i] ; j <= M ; ++j) DP[i][j] |= DP[i-1][j-A[i]];
        }
        int Dif = M;
        for(int j = 0 ; j <= M ; ++j){
            if(DP[N][j]){
                int D = M - (j << 1);
                D = D < 0 ? -D : D;
                if(D < Dif) Dif = D;
            }
        }
        printf("%d\n",Dif);
    }
    return 0;
}


