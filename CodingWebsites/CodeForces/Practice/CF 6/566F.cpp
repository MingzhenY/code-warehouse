#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 1000007
using namespace std;
int N[maxn],DP[maxn]; 
int n;
int main(void)
{
	freopen("566F.txt","r",stdin); 
	while(~scanf("%d",&n)){
		memset(N,0,sizeof(N));
		memset(DP,0,sizeof(DP));
		for(int i=0;i<n;++i){
			int x;scanf("%d",&x);
			DP[x]++;N[x]++;
		}
		for(int i=1;i<=1000000;++i){
			for(int j=i<<1;j<=1000000;j+=i){
				DP[j]=max(DP[j],DP[i]+N[j]);
			}
		}
		int ANS=0;
		for(int i=1;i<=1000000;++i) ANS=max(ANS,DP[i]);
		printf("%d\n",ANS);
	}
return 0;
}

