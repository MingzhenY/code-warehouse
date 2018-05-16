#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 100001
#define inf 1000000012
using namespace std;
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;} return a;}
int n,t;
int minx[maxn<<2];
int numx[maxn<<2];
int gcdx[maxn<<2];
void PushUp(int rt){
	if(minx[rt<<1] == minx[rt<<1|1]){
		minx[rt]=minx[rt<<1];
		numx[rt]=numx[rt<<1]+numx[rt<<1|1];
	}
	else if(minx[rt<<1]<minx[rt<<1|1]){
		minx[rt]=minx[rt<<1];
		numx[rt]=numx[rt<<1];
	}
	else{
		minx[rt]=minx[rt<<1|1];
		numx[rt]=numx[rt<<1|1];
	}
	gcdx[rt]=gcd(gcdx[rt<<1],gcdx[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&minx[rt]);
		numx[rt]=1;
		gcdx[rt]=minx[rt];
		return;
	}
	int m=(l+r)>>1;
	if(l <=m) build(l,m,rt<<1);
	if(r > m) build(m+1,r,rt<<1|1);
	PushUp(rt);
}
int GCD,MINX,NUMX;
void query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		GCD=gcd(GCD,gcdx[rt]);
		if(MINX==minx[rt]){
			NUMX+=numx[rt];
		}
		else if(minx[rt] < MINX){
			MINX=minx[rt];
			NUMX=numx[rt];
		}
		return;
	}
	int m=(l+r)>>1;
	if(L <=m) query(L,R,l,m,rt<<1);
	if(R > m) query(L,R,m+1,r,rt<<1|1);
}
int main(void)
{
	freopen("474F.txt","r",stdin); 
	while(~scanf("%d",&n)){
		build(1,n,1);
		scanf("%d",&t);
		for(int i=0;i<t;++i){
			int L,R;
			scanf("%d%d",&L,&R);
			GCD=0;MINX=inf;NUMX=0;
			query(L,R,1,n,1);
			int ANS=R-L+1;
			if(GCD==MINX) ANS-=NUMX;
			printf("%d\n",ANS);
		}
	}
return 0;
}














