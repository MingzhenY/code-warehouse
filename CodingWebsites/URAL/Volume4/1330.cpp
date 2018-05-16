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
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int sum[maxn<<2];
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int ANS;
void query(int L,int R,int l,int r,int rt){
	if(L <=l &&r <=R){
		ANS+=sum[rt];
		return;
	}
	int m=(l+r)>>1;
	if(L <=m)  query(L,R,ls);
	if(R > m)  query(L,R,rs);
}
int N,Q;
int main(void)
{freopen("1330.txt","r",stdin); 
	while(cin>>N){
		build(1,N,1);
		cin>>Q;
		while(Q--){
			int a,b;
			scanf("%d%d",&a,&b);
			ANS=0;
			query(a,b,1,N,1);
			printf("%d\n",ANS);
		}
	}
return 0;
}








