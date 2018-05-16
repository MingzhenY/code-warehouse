#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int position[5][1000];//记录position[i][j]记录第i行中，数字j出现的位置。 
int a[5][1000];//记录数列 
int dp[1000];//dp[i]表示，以下标i结尾的最长公共子序列长度。 
int main(void)
{
	freopen("463D.txt","r",stdin); 
	while(cin>>n>>k){
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				position[i][--a[i][j]]=j;
			}
		}
		int ans=0;
		for(int j=0;j<n;++j){//对于 j 
			int maxn=0;
			for(int p=0;p <j;++p){//对于 以（j之前的每个点） 结尾的最长序列，判断j可不可以加进去 
				int i;
				for(i=1;i<k&&position[i][a[0][p]]<position[i][a[0][j]];++i) ; 
				if(i==k&&dp[p]>maxn){//求这些可以加进去的点中，dp值最大的一个 
						maxn=dp[p];// 
				}
			}
			dp[j]=maxn+1;//最大dp值加上1
			ans=max(ans,dp[j]);
		}
		printf("%d\n",ans);
	}
return 0;
}














