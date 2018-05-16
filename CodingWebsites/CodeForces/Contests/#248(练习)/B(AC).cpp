#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long i=1;(i)<=(n);i++)
#define For(i,n) for(long long i=0;(i)<(n);i++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;

int a[100001];int cur=0;
long long b1[1<<19];
long long b2[1<<19];
int S=1;
void update(int rt)
{
	if(S==1) b1[rt]=b1[rt<<1]+b1[rt<<1|1];
	else b2[rt]=b2[rt<<1]+b2[rt<<1|1];

}
void build(int l,int r,int rt)
{
	if(l==r){
		if(S==1){
			b1[rt]=a[cur++];
		}
		else{
			b2[rt]=a[cur++];
		}
		return;
	}
	int m=(l+r)>> 1 ;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	update(rt);
}

long long query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R){
		if(S==1) return b1[rt];
		else return b2[rt];
	}
	int m=(l+r)>>1;
	long long sum=0;
	if(L<=m) sum+=query(L,R,l,m,rt<<1);
	if(R>m)  sum+=query(L,R,m+1,r,rt<<1|1); 
	return sum;
}
int n,q;
bool cmp(int a,int b) {
	return a<b;
}
int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>n){
		FOR(i,n) scanf("%d",&a[i]);
		S=1;cur=1;
		build(1,n,1);
		//FOR(i,n) OUT1(a[i]);
		//FOR(i,n) cout<<query(i,i,1,n,1)<<endl;
		
		S=2;cur=1;
		sort(a+1,a+n+1,cmp);
		build(1,n,1);
		
		cin>>q;
		for(int i=0;i<q;i++){
			//printf("%d\n",i);
			int type,l,r;
			scanf("%d%d%d",&type,&l,&r);
			S=type;
			printf("%I64d\n",query(l,r,1,n,1));
		}
		
		
	}
return 0;
}
