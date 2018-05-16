#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n,k,m;
long long dp[1001][100];
bool mark[1001][100];
long long tenk[1000];
long long tenm[1000];
long long F(int i,int j,int nx){
	//printf("F(%d,%d)\n",i,j);
	if(~dp[i][j]) return dp[i][j];
	if(!j&&mark[i][j]&&nx){
		if(i==n) return dp[i][j]=1;
		else return dp[i][j]=(9*tenm[n-i-1])%m;
	}
	if(i<n){
		long long ANS=0;
		for(int x=0;x<=9;++x){
			int I=i+1,J=(j+x*tenk[i])%k;
			mark[I][J]=mark[i][j];						
			ANS=(ANS+F(I,J,x))%m;		
		}
		return dp[i][j]=ANS;
	}
}


int main(void)
{
	freopen("507D.txt","r",stdin); 
	while(~scanf("%d%d%d",&n,&k,&m)){
		memset(dp,-1,sizeof(dp));
		memset(mark,0,sizeof(mark));		
		tenm[0]=1%m;tenk[0]=1%k;
		for(int i=1;i<1000;++i) tenm[i]=(tenm[i-1]*10)%m,tenk[i]=(tenk[i-1]*10)%k;
		long long ANS=F(0,0,0);
		cout<<ANS <<endl;
	}
	
	
return 0;
}














