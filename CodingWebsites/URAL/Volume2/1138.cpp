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

int dp[20001];
int n,s; 
int main(void)
{freopen("1138.txt","r",stdin); 
	while(cin>>n>>s){
		for(int i=0;i<20001;++i) dp[i]=-inf;
		dp[s]=1;
		for(int i=s;i<=n;++i){
			int step=100;
			if(i%2==0) step/=2;
			if(i%4==0) step/=2;
			if(i%5==0) step/=5;
			if(i%25==0) step/=5;
			int Step=i*step/100;
			for(int k=Step;k<=i;k+=Step) dp[i+k]=max(dp[i+k],dp[i]+1);
		}
		int ANS=dp[s];
		for(int i=s;i<=n;++i) ANS=max(ANS,dp[i]);
		cout<<ANS <<endl;
	}
return 0;
}








