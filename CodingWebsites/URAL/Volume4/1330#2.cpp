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
#define maxn 10005
using namespace std;
int sum[maxn<<2];
int N,Q,ANS,n;
void query(int L,int R){
	for(int s=n+L-2,t=n+R;s^t^1;s>>=1,t>>=1){
		if(~s&1) ANS+=sum[s^1];
		if(t&1)  ANS+=sum[t^1];
	}
}
int main(void)
{freopen("1330.txt","r",stdin); 
	while(cin>>N){
		N+=2;n=1;
		while(n <N) n <<=1;
		sum[n]=0;
		for(int i=n+1;i<=n+N-2;i++) scanf("%d",&sum[i]);
		for(int i=n+N-1;i<2*n;i++) sum[i]=0;
		for(int i=n-1;i>0;i--) sum[i]=sum[i<<1]+sum[i<<1|1];
		cin>>Q;
		while(Q--){
			int a,b;
			scanf("%d%d",&a,&b);
			ANS=0;
			query(a+1,b+1);
			printf("%d\n",ANS);
		}
	}
return 0;
}








