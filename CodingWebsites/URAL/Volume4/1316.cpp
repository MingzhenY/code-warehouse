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
#define maxn 1000000
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int number[maxn<<2];
void PushUp(int rt){
	number[rt]=number[rt<<1]+number[rt<<1|1];
}
void build(int l,int r,int rt){
	if(l==r){
		number[l]=0;
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	PushUp(rt);
}
int N;
void add(int X,int C,int l,int r,int rt){
	if(l==r){
		number[rt]+=C;
		return;
	}
	int m=(l+r)>>1;
	if(X<=m) add(X,C,ls);
	else add(X,C,rs);
	PushUp(rt);
}
int Left; 
int query(int L,int R,int l,int r,int rt){
	if(L <=l&&r <=R){
		return number[rt];
	}
	int ANS=0;
	int m=(l+r)>>1;
	if(L <=m) ANS+=query(L,R,ls);
	if(R > m) ANS+=query(L,R,rs);
	return ANS;
}

int main(void)
{freopen("1316.txt","r",stdin); 
	N=1;while(N <maxn) N <<=1;
	build(1,N,1);
	char op[20];double ANS=0.0;
	double k;int X,n;
	while(~scanf("%s",op)){
		scanf("%lf",&k);
		X=floorl(k*100.0+0.5);
		switch(op[0]){
			case 'B':add(X,1,1,N,1);break;
			case 'D':add(X,-1,1,N,1);break;
			case 'S':
				scanf("%d",&n);
				ANS+=0.01*min(query(X,N,1,N,1),n);
			break;
		}
		if(op[0]=='Q') break;
	}
	printf("%.2f\n",ANS);
return 0;
}








