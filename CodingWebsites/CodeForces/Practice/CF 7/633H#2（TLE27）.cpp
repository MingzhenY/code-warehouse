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
//��Ŀ���� 
int n,m,q;
int A[maxn];
//MO's Algorithm
int ANS[maxn],p;
struct LR{
	int L,R,id;
	bool operator<(const LR &B)const{
		return L/p < B.L/p || L/p == B.L/p && R < B.R; 
	}
}I[maxn];
int Count[maxn];
//쳲��������� 
int Fibs[maxn<<1]; 
//��ɢ��
int Rank[maxn],Rn;
//�߶���--�����޸� 
int Shift[maxn<<2],VL[maxn<<2],V[maxn<<2];
int L[maxn<<2],R[maxn<<2],M[maxn<<2];
//��ɢ�� 
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
//쳲��������� 
void GetFibs(){
	Fibs[Rn]=0;
	Fibs[Rn+1]=1;
	for(int i=2;i<=Rn;++i) Fibs[Rn+i]=(Fibs[Rn+i-1]+Fibs[Rn+i-2])%m;
	for(int i=1;i<=Rn;++i) Fibs[Rn-i]=(Fibs[Rn-i+2]-Fibs[Rn-i+1]+m)%m;
}
//�߶���--�����޸�  Fibs_��ͷ 
void Fibs_Build(int l,int r,int rt){
	L[rt]=l;R[rt]=r;M[rt]=(l+r)>>1;
	if(l==r) return;
	int m=(l+r)>>1;
	Fibs_Build(l,m,rt<<1);
	Fibs_Build(m+1,r,rt<<1|1);
}
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
void Fibs_Add(int X,int rt){
	if(L[rt]==R[rt]){
		VL[rt]=Rank[L[rt]]%m*Fibs[Rn+Shift[rt]-1]%m;
		V[rt]=Rank[L[rt]]%m*Fibs[Rn+Shift[rt]]%m;
		return;
	}
	Fibs_PushDown(rt);
	if(X <= M[rt]) Fibs_Add(X,rt<<1);
	else       Fibs_Add(X,rt<<1|1);
	Fibs_PushUp(rt);
}
void Fibs_Remove(int X,int rt){
	if(L[rt]==R[rt]){
		V[rt]=VL[rt]=0;
		return;
	}
	Fibs_PushDown(rt);
	if(X <= M[rt]) Fibs_Remove(X,rt<<1);
	else       Fibs_Remove(X,rt<<1|1);
	Fibs_PushUp(rt);
}
void Fibs_Update(int LL,int RR,int X,int rt){
	if(LL <= L[rt] && R[rt] <= RR){
		Shift[rt]+=X;
		Fibs_Shift(rt,X);
		return;
	}
	Fibs_PushDown(rt);
	if(LL <= M[rt]) Fibs_Update(LL,RR,X,rt<<1);
	if(RR >  M[rt]) Fibs_Update(LL,RR,X,rt<<1|1);
	Fibs_PushUp(rt);
}
//Mo's Algorithm
void Mo_Clear(){
	memset(Count,0,sizeof(Count));
	Fibs_Clear();
}
void Mo_Add(int v){
	int k = GetRank(v);
	if(!Count[k]++){
		Fibs_Add(k,1);
		Fibs_Update(k,Rn,1,1);
	}
}
void Mo_Remove(int v){
	int k=GetRank(v);
	if(!--Count[k]){
		Fibs_Remove(k,1);
		Fibs_Update(k,Rn,-1,1);
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
		SetRank();//��ɢ�� 
		scanf("%d",&q);
		for(int i=1;i<=q;++i) scanf("%d%d",&I[I[i].id=i].L,&I[i].R);
		p = sqrt(n);
		sort(I+1,I+q+1);//�������� 
		GetFibs();//��ʼ��Fibs����
		Fibs_Build(1,Rn,1);//�����߶��� 
		int L,R=n+1;
		for(int i=1;i<=q;++i){
			if(R > I[i].R){
				Mo_Clear();
				L=1;R=0;
			}
			while(R < I[i].R) Mo_Add(A[++R]);
			while(L < I[i].L) Mo_Remove(A[L++]);
			while(L > I[i].L) Mo_Add(A[--L]);
			ANS[I[i].id]=V[1];
		}
		for(int i=1;i<=q;++i){
			printf("%d\n",ANS[i]);
		}
	}
return 0;
}


