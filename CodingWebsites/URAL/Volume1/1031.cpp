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

long long L1,L2,L3,C1,C2,C3;
int N,start,end;
long long dis[10000];
long long dp[10000];
long long cost(long long dis);
int main(void)
{freopen("1031.txt","r",stdin); 
	while(cin>>L1>>L2>>L3>>C1>>C2>>C3){
		cin>>N>>start>>end;start--;end--;
		if(start>end) {
			int t=start;
			start=end;
			end=t;
		}
		memset(dis,0,sizeof(dis));
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<N;i++){
			scanf("%d",&dis[i]);
		}
		//¿ªÊ¼dp
		dp[start]=0ll;
		for(int i=start;i<end;i++){
			for(int j=start+1;dis[j]-dis[i]<=L3;j++){
				if(~dp[j]){
					if(dp[i]+cost(dis[j]-dis[i])<dp[j]) dp[j]=dp[i]+cost(dis[j]-dis[i]);
				}
				else dp[j]=dp[i]+cost(dis[j]-dis[i]);
			}
		} 
		cout<<dp[end]<<endl;
	}		
return 0;
}
long long cost(long long dis){
	if(!dis) return 0;
	if(dis<=L1) return C1;
	if(dis<=L2) return C2;
	if(dis<=L3) return C3;
	return -1;
}







