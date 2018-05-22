#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int DP[101][101][101];//DP[i][j][k]: k个数，范围从1到i，使这k个数的和为j的方法种数（无顺序，即2+3和3+2算同一种）
void Calculate(int m,int n){
    memset(DP,0,sizeof(DP));
    DP[0][0][0] = 1;
    for(int i = 1 ; i <= m ; ++i){//Add i
        for(int j = 0 ; j <= m ; ++j){
            for(int k = 0 ; k <= n ; ++k){
                for(int t = 0 , J = j ; k + t <= n && J <= m ; ++t , J += i){
                    //DP[i - 1][j][k] -> DP[i][j+t*i][k+t]
                    DP[i][J][k+t] += DP[i - 1][j][k];
                }
            }
        }
    }
}
int main(){
    freopen("P1185.txt","r",stdin);
    int m,n;
    Calculate(100,100);
    while(~scanf("%d%d",&m,&n)){
        int ANS = 0 ;
        for(int i = 0 ; i <= n ; ++i) ANS += DP[m][m][i];
        printf("%d\n",ANS);
    }
    return 0;
}


