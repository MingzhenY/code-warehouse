#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
int a[20];int N;
bool dp[20][2000000];
int A(int a){//求绝对值 
	return a>0?a:-a;
}
int main(void)
{freopen("1005.txt","r",stdin); 
	cin>>N;
	memset(dp,0,sizeof(dp));
	int S=0;
	For(i,N) scanf("%d",&a[i]),S+=a[i];
	dp[0][0]=1;dp[0][a[0]]=1;
	for(int i=1;i<N;i++){
		for(int j=0;j<S;j++){
			dp[i][j]=dp[i-1][j];
			if(j-a[i]>=0) dp[i][j]=dp[i][j]||dp[i-1][j-a[i]];
		}
	}
	int ANS=inf;
	for(int i=0;i<S;i++){
		if(dp[N-1][i]){//若存在一个组合的Sum为i 
			//则这么分组的差为:  S-2i; 
			if(A(S-2*i)<ANS) ANS=A(S-2*i);
		}
	}
	cout<<ANS<<endl;
return 0;
}








