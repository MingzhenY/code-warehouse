#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n,q,N,x;
int st[400010];
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;} return a;}
int query(int l,int r){
	int ANS=0;
	for(int s=N+l-1,t=N+r+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) ANS=gcd(ANS,st[s^1]);
		if(t&1)  ANS=gcd(ANS,st[t^1]);
	}
	return ANS;
}
int Le(int left,int x){//以 left 为左端点，数值大于x的最大下标 
	int L,R,M;
	L=left;R=n+1;
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(query(left,M)>x) L=M;
	else R=M;
	goto begin;
	end:
	if(st[N+L]==x) --L;
	return L;
}
int Ri(int left,int x){//以 left 为左端点，数值大于等于x的最大下标 
	int L,R,M;
	L=left;R=n+1;
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(query(left,M)>=x) L=M;
	else R=M;
	goto begin;
	end:
	return L;
}
int main(void)
{
	freopen("475D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		N=1;while(N <n+2) N <<=1;
		memset(st,0,sizeof(st));
		for(int i=1;i<=n;++i) scanf("%d",&st[N+i]);
		for(int i=N-1;i>=1;--i) st[i]=gcd(st[i<<1],st[i<<1|1]); 
		scanf("%d",&q);
		for(int j=0;j<q;++j){
			scanf("%d",&x);
			int ANS=0;
			for(int i=1;i<=n;++i){
				ANS+=Ri(i,x)-Le(i,x);
			}
			printf("%d\n",ANS);
		}
	}
return 0;
}














