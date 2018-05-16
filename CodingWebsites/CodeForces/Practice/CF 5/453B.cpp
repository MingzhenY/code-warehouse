#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int maxp[60],n,a[100];
int p[17];int np;
int pi[60];
int fact[60];
int Break(int k){
	int Mask=0;
	while(k>1){
		int prime=maxp[k];
		while(k%prime==0) k/=prime;
		Mask|=1<<(pi[prime]);
	}
	return Mask;
}
int dp[101][1<<17];
int path[101][1<<17];
int num[101][1<<17];
void Show(int i,int j){
	//printf("(%d,%d) dp[i][j]=%d  path[i][j]=%d num[i][j]=%d\n",i,j,dp[i][j],path[i][j],num[i][j]); 
	if(i>0){
		Show(i-1,path[i][j]);
		printf("%d ",num[i][j]);
	}
}
int main(void)
{
	freopen("453B.txt","r",stdin); 
	memset(maxp,-1,sizeof(maxp));np=0;
	for(int i=2;i<60;++i){
		if(~maxp[i]) continue;p[np]=i;pi[i]=np++;
		for(int j=i;j<60;j+=i) maxp[j]=i;
	}
	for(int i=1;i<60;++i) fact[i]=Break(i);
	while(cin>>n){
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		dp[0][0]=0;int m=1<<17;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(~dp[i][j]){
					for(int k=1;k <60;++k){
						if(j&fact[k]) continue;
						int J=j|fact[k],D=dp[i][j]+abs(a[i]-k);
						if(!~dp[i+1][J]||D <dp[i+1][J]){
							dp[i+1][J]=D;
							path[i+1][J]=j;
							num[i+1][J]=k;
						}
					}	
				}
			}
		}
		int I=n,J=-1,ans=0x7fffffff;
		for(int j=0;j<m;++j){
			if(~dp[I][j]&&dp[I][j]<ans){
				ans=dp[I][j];
				J=j;
			}
		}
		Show(I,J); 
		printf("\n");
	}
	
		
return 0;
}














