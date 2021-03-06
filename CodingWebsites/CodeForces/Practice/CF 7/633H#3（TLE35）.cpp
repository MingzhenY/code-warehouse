#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 30001
using namespace std;
//题目数据 
int n,m,q;
int A[maxn],RankA[maxn];
//MO's Algorithm
int ANS[maxn],p;
struct LR{
	int L,R,id;
	bool operator<(const LR &B)const{
		return L/p < B.L/p || L/p == B.L/p && R < B.R; 
	}
}I[maxn];
int Count[maxn];
//斐波那契数列 
int Fibs[maxn<<1]; 
//离散化
int Rank[maxn],Rn;
//线段树--区间修改 
int Shift[maxn<<2],VL[maxn<<2],V[maxn<<2];
//离散化 
void SetRank(){
	sort(Rank+1,Rank+Rn+1);
	int I=1;
	for(int i=2;i<=Rn;++i)
		if(Rank[i]!=Rank[i-1]) 
			Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=Rn,M;//[L,R] first >= x
	while(L^R){
		M = (L+R)>>1;
		if(Rank[M] < x) L=M+1;
		else R = M;
	}
	return L;
}
//斐波那契数列 
void GetFibs(){
	Fibs[Rn]=0;
	Fibs[Rn+1]=1;
	for(int i=2;i<=Rn;++i) Fibs[Rn+i]=(Fibs[Rn+i-1]+Fibs[Rn+i-2])%m;
	for(int i=1;i<=Rn;++i) Fibs[Rn-i]=(Fibs[Rn-i+2]-Fibs[Rn-i+1]+m)%m;
}
//线段树--区间修改  Fibs_开头 
void Fibs_Clear(){
	memset(Shift,0,sizeof(Shift));
	memset(VL,0,sizeof(VL));
	memset(V,0,sizeof(V));
}
void Fibs_PushUp(int rt){
	V[rt]=(V[rt<<1]+V[rt<<1|1])%m;
	VL[rt]=(VL[rt<<1]+VL[rt<<1|1])%m;
}
void Fibs_Shift(int rt,int shift){
	int NV,NVL;
	NV =(VL[rt]*Fibs[Rn+shift]+V[rt]*Fibs[Rn+shift+1])%m;
	NVL =(VL[rt]*Fibs[Rn+shift-1]+V[rt]*Fibs[Rn+shift])%m;
	V[rt]=NV;VL[rt]=NVL;
}
void Fibs_PushDown(int rt){
	if(Shift[rt]){
		Shift[rt<<1]+=Shift[rt];
		Shift[rt<<1|1]+=Shift[rt];
		Fibs_Shift(rt<<1,Shift[rt]);
		Fibs_Shift(rt<<1|1,Shift[rt]);
		Shift[rt]=0;
	}
}
void Fibs_Add(int X,int l,int r,int rt){
	if(l==r){
		VL[rt]=Rank[l]%m*Fibs[Rn+Shift[rt]-1]%m;
		V[rt]=Rank[l]%m*Fibs[Rn+Shift[rt]]%m;
		return;
	}
	int m=(l+r)>>1;
	Fibs_PushDown(rt);
	if(X <= m) Fibs_Add(X,l,m,rt<<1);
	else       Fibs_Add(X,m+1,r,rt<<1|1);
	Fibs_PushUp(rt);
}
void Fibs_Remove(int X,int l,int r,int rt){
	if(l==r){
		V[rt]=VL[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	Fibs_PushDown(rt);
	if(X <= m) Fibs_Remove(X,l,m,rt<<1);
	else       Fibs_Remove(X,m+1,r,rt<<1|1);
	Fibs_PushUp(rt);
}
void Fibs_Update(int L,int R,int X,int l,int r,int rt){
	if(L <= l && r <= R){
		Shift[rt]+=X;
		Fibs_Shift(rt,X);
		return;
	}
	int m=(l+r)>>1;
	Fibs_PushDown(rt);
	if(L <= m) Fibs_Update(L,R,X,l,m,rt<<1);
	if(R >  m) Fibs_Update(L,R,X,m+1,r,rt<<1|1);
	Fibs_PushUp(rt);
}
//Mo's Algorithm
void Mo_Init(){
	memset(Count,0,sizeof(Count));
	Fibs_Clear();
	for(int i=1;i<=n;++i) RankA[i]=GetRank(A[i]);
}
void Mo_Add(int k){
	if(!Count[k]++){
		Fibs_Add(k,1,Rn,1);
		Fibs_Update(k,Rn,1,1,Rn,1);
	}
}
void Mo_Remove(int k){
	if(!--Count[k]){
		Fibs_Remove(k,1,Rn,1);
		Fibs_Update(k,Rn,-1,1,Rn,1);
	}
} 
int main(void)
{
	freopen("633H.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		Rn=0;
		for(int i=1;i<=n;++i) {
			scanf("%d",&A[i]);
			Rank[++Rn]=A[i];
		}
		SetRank();//离散化 
		scanf("%d",&q);
		for(int i=1;i<=q;++i) scanf("%d%d",&I[I[i].id=i].L,&I[i].R);
		p = sqrt(n);
		sort(I+1,I+q+1);//区间排序 
		GetFibs();//初始化Fibs数组
		Mo_Init();
		int L=1,R=0;
		for(int i=1;i<=q;++i){
			while(R > I[i].R) Mo_Remove(RankA[R--]);
			while(R < I[i].R) Mo_Add(RankA[++R]);
			while(L < I[i].L) Mo_Remove(RankA[L++]);
			while(L > I[i].L) Mo_Add(RankA[--L]);
			ANS[I[i].id]=V[1];
		}
		for(int i=1;i<=q;++i){
			printf("%d\n",ANS[i]);
		}
	}
return 0;
}


