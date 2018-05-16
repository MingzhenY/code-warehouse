#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,t;
double p;
double dp[2001][2001]; 
double F(int i,int j){
	if(dp[i][j]>-0.5) return dp[i][j];
	if(i ==0||j==0) return dp[i][j]=0;
	if(j==1) return dp[i][j]=p;
	return dp[i][j]=p*(1+F(i-1,j-1))+(1-p)*F(i,j-1);
}
int main(void)
{
	freopen("518D.txt","r",stdin); 
	while(cin>>n>>p>>t){
		for(int i=0;i<=n;++i){
			for(int j=0;j<=t;++j){
				dp[i][j]=-1;
			}
		}
		printf("%.7f\n",F(n,t));
	}
return 0;
}














