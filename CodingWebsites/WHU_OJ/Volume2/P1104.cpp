#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,A[201],Sum;
short int DP[2][8001][2];
int main(){// WA
    freopen("P1104.txt","r",stdin);
    while(~scanf("%d",&n)){
        Sum=0;
        memset(DP,0,sizeof(DP));
        for(int i=1;i<=n;++i)  scanf("%d",&A[i]),Sum+=A[i];
        DP[0][0][0]=DP[0][0][1]=true;
        for(int i=1;i<=n;++i){
            int I=i&1,_I=!I;
            for(int j=0;j<=8000;++j){
                DP[I][j][0] = DP[_I][j][0];
                DP[I][j][1] = DP[_I][j][1];
            }
            for(int j = A[i] ; j <= 8000 ; ++j){
                DP[I][j][0] = min(DP[I][j][0],(short int)(DP[_I][j-A[i]][0]+1));
                DP[I][j][1] = max(DP[I][j][1],(short int)(DP[_I][j-A[i]][1]+1));
            }
        }
        bool Found = false;
        int L,R;
        if(n <= 10) L=0,R=n;
        else{
            L = (n+1)/2 - 5;
            R = n/2 + 5;
        }
        for(int i=(Sum+1)/2;i<=Sum;++i){
            for(int k=L;k<=R;++k){
                if(DP[n&1][i][0] <= k && k <= DP[n&1][i][1]){
                    printf("%d %d\n",i,Sum-i);
                    Found = true;
                    break;
                }
            }
            if(Found) break;
        }
        if(!Found) printf("ERROR\n");
    }
    return 0;
}


