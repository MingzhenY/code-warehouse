#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200001
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1 
using namespace std;
int L[maxn<<2][2];
int R[maxn<<2][2];
int Max[maxn<<2][2];
bool Pure[maxn<<2][2];
void PushUp(int rt,int k){
	Pure[rt][k]=Pure[rt<<1][k]&&Pure[rt<<1|1][k];
	Max[rt][k]=max(R[rt<<1][k]+L[rt<<1|1][k],max(Max[rt<<1][k],Max[rt<<1|1][k]));
	L[rt][k]=Pure[rt<<1][k]?L[rt<<1][k]+L[rt<<1|1][k]:L[rt<<1][k];
	R[rt][k]=Pure[rt<<1|1][k]?R[rt<<1|1][k]+R[rt<<1][k]:R[rt<<1|1][k];
}
void Build(int l,int r,int rt,int k){
	if(l==r){
		Pure[rt][k]=L[rt][k]=R[rt][k]=Max[rt][k]=1;
		return;
	}
	int m=(l+r)>>1;
	Build(ls,k);
	Build(rs,k);
	PushUp(rt,k); 
}
void Change(int X,int l,int r,int rt,int k){
	if(l==r){
		Pure[rt][k]=L[rt][k]=R[rt][k]=Max[rt][k]=0;
		return;
	}
	int m=(l+r)>>1;
	if(X <= m) Change(X,ls,k);
	else       Change(X,rs,k);
	PushUp(rt,k); 
} 
int main(void)
{
	freopen("527C.txt","r",stdin); 
	int w,h,n;
	while(cin>>w>>h>>n){
		Build(1,h-1,1,0);Build(1,w-1,1,1);
		for(int i=0;i<n;++i){
			char x;int v;
			scanf(" %c%d",&x,&v);
			x=='H'?Change(v,1,h-1,1,0):Change(v,1,w-1,1,1);
			printf("%I64d\n",(long long)(Max[1][0]+1)*(Max[1][1]+1));
		}
	}
return 0;
}














