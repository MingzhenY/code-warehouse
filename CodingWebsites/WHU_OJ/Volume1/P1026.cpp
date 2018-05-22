#include <iostream>
#include <cstdio>
#include <cstdlib>
#define OUT3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<endl;
using namespace std;
int T,N;
int A[1001][1001];
int DP[1001][1001];
int main(){
    freopen("P1026.txt","r",stdin);
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d",&N);
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                scanf("%d",&A[i][j]);
        
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                DP[i][j]= A[i][j] + max(DP[i-1][j-1],max(DP[i-1][j],DP[i-1][j+1]));
        
        for(int j=2;j<=N;++j) 
            DP[N][j]=max(DP[N][j],DP[N][j-1]);
        
        printf("Case %d:\n%d\n",C,DP[N][N]);
        if(C^T) printf("\n");
    }
    return 0;
}


