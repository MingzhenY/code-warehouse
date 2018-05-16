#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200007
using namespace std;
int n,m;
int d[maxn];
long long s[maxn];
int h[maxn];

struct T{
	long long x;
	int i;
}A[maxn<<2],B[maxn<<2];
void PushUp(int rt){
	if(A[rt<<1].x>=A[rt<<1|1].x) A[rt]=A[rt<<1];
	else A[rt]=A[rt<<1|1];
	if(B[rt<<1].x>=B[rt<<1|1].x) B[rt]=B[rt<<1];
	else B[rt]=B[rt<<1|1];
}
void Build(int l,int r,int rt){
	if(l==r){
		A[rt].i=l;A[rt].x=h[r]-s[r-1];
		B[rt].i=l;B[rt].x=h[r]+s[r-1];
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	PushUp(rt);
}
T QA(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R) return A[rt];
	int m=(l+r)>>1;
	T AL,AR;int cnt=0;
	if(L <= m) AL=QA(L,R,l,m,rt<<1),cnt+=1;
	if(R >  m) AR=QA(L,R,m+1,r,rt<<1|1),cnt+=2;
	switch(cnt){
		case 3:
			if(AL.x>AR.x) return AL;
			else return AR;
			break;
		case 1:
			return AL;
			break;
		case 2:
			return AR;
			break;
	}
	return AL;
}
T QB(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R) return B[rt];
	int m=(l+r)>>1;
	T BL,BR;int cnt=0;
	if(L <= m) BL=QB(L,R,l,m,rt<<1),cnt+=1;
	if(R >  m) BR=QB(L,R,m+1,r,rt<<1|1),cnt+=2;
	switch(cnt){
		case 3:
			if(BL.x>BR.x) return BL;
			else return BR;
			break;
		case 1:
			return BL;
			break;
		case 2:
			return BR;
			break;
	}
	return BL;
}
int main(void)
{
	freopen("515E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		int N=n <<1;
		for(int i=1;i<=n;++i) {scanf("%d",&d[i]);d[i+n]=d[i];}
		for(int i=1;i<=n;++i) {scanf("%d",&h[i]);h[i]*=2;h[i+n]=h[i];}
		s[0]=0;for(int i=1;i<=N;++i) s[i]=s[i-1]+d[i];
		Build(1,N,1);
		for(int i=0;i<m;++i){
			int a,b,L,R;scanf("%d%d",&a,&b);
			if(a<=b){L=b+1;R=a+n-1;}
			else {L=b+1;R=a-1;}
			T MaxA=QA(L,R,1,N,1);
			T MaxB=QB(L,R,1,N,1);
			if(MaxA.i!=MaxB.i){
				cout<<(MaxA.x+MaxB.x)<<endl;
				continue;
			}
			else{
				long long AL,BR;
				if(MaxA.i>L) AL=QA(L,MaxA.i-1,1,N,1).x+MaxB.x; else AL=0;
				if(MaxB.i<R) BR=QB(MaxB.i+1,R,1,N,1).x+MaxA.x; else BR=0;
				cout<<max(AL,BR)<<endl;
			}
		}
	} 
return 0;
}














