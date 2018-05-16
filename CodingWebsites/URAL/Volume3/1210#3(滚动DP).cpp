#include <iostream>
#include <cstdio>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int dp[2][31];
int main(void)
{freopen("1210.txt","r",stdin); 
	int N;
	while(cin>>N){
		For(i,2) For(j,31) dp[i][j]=inf;
		dp[0][1]=0;int P;
		FOR(i,N){//表示等级 
			scanf("%d",&P);int Cur=i&1;
			FOR(j,P){
				int a,b;
				dp[Cur][j]=inf;
				while(scanf("%d",&a)&&a){
					scanf("%d",&b);
					dp[Cur][j]=min(dp[Cur][j],dp[!Cur][a]+b);
				}
			}
			if(i<N) scanf(" %*c");
		}
		//计算
		int ANS=inf;
		FOR(i,P) ANS=min(ANS,dp[N&1][i]);
		cout<<ANS<<endl;
	}

return 0;
}








