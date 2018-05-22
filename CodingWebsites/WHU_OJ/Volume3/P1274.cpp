#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int maxprime[1121];
int prime[200],pn;
int DP[188][1121][15];//DP[i][j][k]: k个数，范围从prime[1]到prime[i]，使这k个数的和为j的方法种数（无顺序）
void Calculate(int m,int n){
    memset(maxprime,-1,sizeof(maxprime));
    pn = 0;
    for(int i = 2 ; i <= n ; ++i){
        if(~maxprime[i]) continue;
        prime[++pn] = i;
        for(int j = i ; j <= n ; j += i) maxprime[j] = i;
    }
    memset(DP,0,sizeof(DP));
    DP[0][0][0] = 1;
    for(int i = 1 ; i <= m ; ++i){//Add prime[i]
        for(int j = 0 ; j <= n ; ++j){
            for(int k = 0 ; k <= 14 ; ++k){
                DP[i][j][k] += DP[i - 1][j][k];
                if(j + prime[i] <= n && k < 14)
                    DP[i][j + prime[i]][k + 1] += DP[i - 1][j][k];
            }
        }
    }
}
int main(){
    freopen("P1274.txt","r",stdin);
    Calculate(187,1120);
    int n,k;
    while(~scanf("%d%d",&n,&k)&&n&&k){
        printf("%d\n",DP[187][n][k]);
    }
    return 0;
}


