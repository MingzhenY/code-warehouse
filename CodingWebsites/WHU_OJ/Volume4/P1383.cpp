#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[1001][1001];
int DP[1001][1001];
int r,c,t;
int main(){
    freopen("P1383.txt","r",stdin);
    scanf("%d",&t);
    for(int C=1;C<=t;++C){
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                scanf("%d",&A[i][j]);
                DP[i][j]=A[i][j]+max(DP[i-1][j-1],max(DP[i-1][j],DP[i][j-1]));
            }
        }
        printf("Case #%d: %d\n",C,DP[r][c]);
    }
    return 0;
}


