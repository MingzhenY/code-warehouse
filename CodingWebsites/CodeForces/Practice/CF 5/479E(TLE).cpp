#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define M 1000000007
#define maxn 5010
using namespace std;
int n,a,b,k,bI;
//线段树 
long long st[maxn<<2];
long long add[maxn<<2];
long long C[maxn];

void PushUp(int rt){st[rt]=(st[rt<<1]+st[rt<<1|1])%M;}
void PushDown(int rt,int L,int R){
	if(add[rt]){
		st[rt<<1]=(st[rt<<1]+add[rt]*L)%M;
		add[rt<<1]=(add[rt<<1]+add[rt])%M;
		st[rt<<1|1]=(st[rt<<1|1]+add[rt]*R)%M;
		add[rt<<1|1]=(add[rt<<1|1]+add[rt])%M;
		add[rt]=0;
	}
}
void ST_Init(){
	memset(st,0,sizeof(st));
	memset(add,0,sizeof(add));
}
void ADD(int L,int R,long long C,int l,int r,int rt){
	if(L <= l && r <= R){
		st[rt]=(st[rt]+C*(r-l+1))%M;
		add[rt]=(add[rt]+C)%M;
		return;
	}
	int m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);
	if(L <= m) ADD(L,R,C,l,m,rt<<1);
	if(R >  m) ADD(L,R,C,m+1,r,rt<<1|1);
	PushUp(rt);
}
long long query(int X,int l,int r,int rt){
	if(l==r){
		return st[rt];
	}
	int m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);
	if(X <=m) return query(X,l,m,rt<<1);
	else return query(X,m+1,r,rt<<1|1);
}
void ClearALL(int l,int r,int rt){
	if(l==r){
		C[l]=st[rt];
		return;
	}
	int m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);
	ClearALL(l,m,rt<<1);
	ClearALL(m+1,r,rt<<1|1);
}

int main(void)
{
	freopen("479E.txt","r",stdin); 
	while(cin>>n>>a>>b>>k){
		ST_Init();
		ADD(a,a,1,1,n,1);
		for(int i=0;i<k;++i){
			ClearALL(1,n,1);ST_Init();
			for(int j=1;j<=n;++j){
				if(j==b) continue;
				int D=(j>b?j-b:b-j)-1;
				ADD(max(1,j-D),min(n,j+D),C[j],1,n,1);
				ADD(j,j,-C[j],1,n,1);
			}/*
			printf("第%d次操作后：\n",i+1);
			for(int tt=1;tt<=n;tt++){
				printf("d[%d]=%d\n",tt,query(tt,1,n,1));
			}*/
		}
		int ANS=st[1]-query(b,1,n,1);
		cout<<ANS<<endl;
	}

		
return 0;
}














