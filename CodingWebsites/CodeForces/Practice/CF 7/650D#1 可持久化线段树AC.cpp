/* 1933 ms	201968 KB  */ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 400007
using namespace std;
//离散化 
int Rank[maxn],Rn;
void SetRank(int n){
	sort(Rank+1,Rank+n+1);
	Rn = 1;
	for(int i=2;i<=n;++i)
		if(Rank[i]^Rank[i-1])
			Rank[++Rn]=Rank[i];
}
int GetRank(int x){
	int L=1,R=Rn,M;//[L,R] first >= x
	while(L^R){
		M = (L+R)>>1;
		if(Rank[M] < x) L = M + 1;
		else R = M;
	}
	return L;
}
int GetRank_R(int x){
	int L=1,R=Rn,M;//[L,R] first > x
	while(L^R){
		M = (L+R)>>1;
		if(Rank[M] <= x) L = M + 1;
		else R = M;
	}
	return L;
}
//题目数据 
int n,m,a,b,k;
int h[maxn];

//LIS部分
int LIS_L[maxn],LIS_R[maxn],Len[maxn],Ln;
int Test_L(int v){
	int L=0,R=Ln+1,M;//[L,R)  last < v
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(Len[M] < v) L = M;
		else R = M;
	}
	return L;
}
int Test_R(int v){
	int L=0,R=Ln+1,M;//[L,R) last > v
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(Len[M] > v) L = M;
		else R = M;
	}
	return L;
}
void LIS(){
	Len[0]=Ln=0;
	for(int i=1;i<=n;++i){
		LIS_L[i] = Test_L(h[i]) + 1;
		if(Ln < LIS_L[i]) Len[++Ln] = h[i];
		else Len[LIS_L[i]]=min(Len[LIS_L[i]],h[i]);
	}
	k = Ln;//记录最长LIS 
	Len[0]=1000000001;Ln=0;
	for(int i=n;i>=1;--i){
		LIS_R[i] = Test_R(h[i]) + 1;
		if(Ln < LIS_R[i]) Len[++Ln] = h[i];
		else Len[LIS_R[i]]=max(Len[LIS_R[i]],h[i]);
	}
}
//主席树部分
int LPS_L[maxn*20],LPS_R[maxn*20],LPS_V[maxn*20],LPS_T[maxn],LPS_TP;
void LPS_Add(int &rt,int l,int r,int x,int v){
	++LPS_TP;
	LPS_L[LPS_TP]=LPS_L[rt];
	LPS_R[LPS_TP]=LPS_R[rt];
	LPS_V[LPS_TP]=max(LPS_V[rt],v);
	rt = LPS_TP;
	if(l==r) return;
	int m = (l + r) >> 1;
	if(x <= m) LPS_Add(LPS_L[rt],l,m,x,v);
	else       LPS_Add(LPS_R[rt],m+1,r,x,v);
}
void LPS_Build(){
	LPS_L[0]=LPS_R[0]=LPS_V[0]=LPS_T[0]=LPS_TP=0;
	for(int i=1;i<=n;++i){
		LPS_Add(LPS_T[i]=LPS_T[i-1],1,Rn,GetRank(h[i]),LIS_L[i]);
	}
}
int LPS_Query(int rt,int l,int r,int x){
	if(l == r) return LPS_V[rt];
	int m = (l + r) >> 1;
	if(x <= m) return LPS_Query(LPS_L[rt],l,m,x);
	else return max(LPS_V[LPS_L[rt]],LPS_Query(LPS_R[rt],m+1,r,x));
}
int RPS_L[maxn*20],RPS_R[maxn*20],RPS_V[maxn*20],RPS_T[maxn],RPS_TP;
void RPS_Add(int &rt,int l,int r,int x,int v){
	++RPS_TP;
	RPS_L[RPS_TP]=RPS_L[rt];
	RPS_R[RPS_TP]=RPS_R[rt];
	RPS_V[RPS_TP]=max(RPS_V[rt],v);
	rt = RPS_TP;
	if(l==r) return;
	int m = (l + r) >> 1;
	if(x <= m) RPS_Add(RPS_L[rt],l,m,x,v);
	else       RPS_Add(RPS_R[rt],m+1,r,x,v);
}
void RPS_Build(){
	RPS_L[n+1]=RPS_R[n+1]=RPS_V[n+1]=RPS_T[n+1]=RPS_TP=0;
	for(int i=n;i>=1;--i){
		RPS_Add(RPS_T[i]=RPS_T[i+1],1,Rn,GetRank(h[i]),LIS_R[i]);
	}
}
int RPS_Query(int rt,int l,int r,int x){
	if(l == r) return RPS_V[rt];
	int m = (l + r) >> 1;
	if(x <= m) return max(RPS_Query(RPS_L[rt],l,m,x),RPS_V[RPS_R[rt]]); 
	else return RPS_Query(RPS_R[rt],m+1,r,x);
}
int Count[maxn];//每种位置的数的数量
int pos[maxn];//第i个数在LIS中的位置，0表示不在LIS中 
int main(void)
{
	freopen("650D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) scanf("%d",&h[i]),Rank[i]=h[i];
		//离散化
		Rank[n+1]=0;Rank[n+2]=1000000001;
		SetRank(n+2);
		//建立LIS数组 
		LIS();
		
		memset(Count,0,sizeof(Count));
		for(int i=1;i<=n;++i){
			int L = LIS_L[i],R = LIS_R[i]; 
			if(L+R==k+1){
				Count[pos[i]=L]++;
			}
			else pos[i]=0;
		} 
		//建主席树 
		LPS_Build();
		RPS_Build();
		
		for(int i=1;i<=m;++i){
			scanf("%d%d",&a,&b);
			int _L = a - 1, _R = a + 1;
			int ANS1=1+LPS_Query(LPS_T[_L],1,Rn,GetRank(b)-1)+RPS_Query(RPS_T[_R],1,Rn,GetRank_R(b));
			int ANS2=Count[pos[a]]^1?k:k-1;
			printf("%d\n",max(ANS1,ANS2));
		}
	}
return 0;
}














