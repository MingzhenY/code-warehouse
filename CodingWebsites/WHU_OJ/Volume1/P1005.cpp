#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n,s;//n<=100,s<=10,0000
int size[100],point[100];
int dp[2][100001];//dp[i][j] is the highest value you can get with first i items and size j.
int main(){
    freopen("P1005.txt","r",stdin);
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i) cin>>size[i]>>point[i];
        cin>>s;
        for(int i=0;i<n;++i){
            int I=i&1,nextI=!I;
            for(int j=0;j<size[i];++j) dp[nextI][j]=dp[I][j];
            for(int j=size[i];j<=s;++j){
                dp[nextI][j]=max(dp[I][j],dp[I][j-size[i]]+point[i]);
            }
        }
        cout<<dp[n&1][s]<<endl;
    }
    return 0;
}


