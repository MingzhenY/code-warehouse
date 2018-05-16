#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,K;
bool A[501];
int dp[501][501];
int cost[501][501];
int D0[501],A0;
int D1[501],A1;
int main(void)
{freopen("1167.txt","r",stdin); 
	ios::sync_with_stdio(false);
	while(cin>>N>>K){
		A1=0;
		for(int i=0;i<N;++i) cin>>A[i],A1+=A[i];
		A0=N-A1;D0[0]=D1[0]=0;
		for(int i=1;i<=N;++i) D1[i]=D1[i-1]+A[i-1],D0[i]=D0[i-1]+!A[i-1];
		memset(cost,0,sizeof(cost));
		for(int i=0;i<=N;++i){
			for(int j=i;j<=N;++j){
				cost[i][j]=(D1[j]-D1[i])*(D0[j]-D0[i]);
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i) dp[i][1]=cost[0][i];
		for(int k=2;k<=K;++k){
			for(int n=k;n<=N;++n){
				int ANS=inf;
				for(int i=1;i<n;++i) ANS=min(ANS,dp[i][k-1]+cost[i][n]);
				dp[n][k]=ANS;
			}
		}
		cout<<dp[N][K]<<endl;
	}
return 0;
}








