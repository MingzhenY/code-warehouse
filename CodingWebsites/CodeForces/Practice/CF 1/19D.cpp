#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
#include <algorithm>
#define maxn 200007
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
//SBT 
int L[maxn],R[maxn],S[maxn],K[maxn],IP,SBT[maxn];
void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;} 
void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void level(int &x,bool flag){//平衡函数 
	if(flag){
		if(S[L[L[x]]]>S[R[x]]) zag(x);
		else if(S[R[L[x]]]>S[R[x]]) zig(L[x]),zag(x);
		else return;
	}
	else{
		if(S[R[R[x]]]>S[L[x]]) zig(x);
		else if(S[L[R[x]]]>S[L[x]]) zag(R[x]),zig(x);
		else return;
	}
	level(L[x],true);level(R[x],false);
	level(x,true);level(x,false);
}
void Insert(int &rt,int v){//加入 
	if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=v;return;}
	v<=K[rt]?Insert(L[rt],v):Insert(R[rt],v);
	++S[rt];level(rt,v<=K[rt]);
}
int Delete(int &rt,int v){//删除 
	int Del;--S[rt];
	if(v==K[rt]||v<K[rt]&&!L[rt]||v>K[rt]&&!R[rt]){
		Del=K[rt];
		if(!L[rt]||!R[rt]) rt=L[rt]+R[rt];
		else K[rt]=Delete(L[rt],v);
	}
	else Del=v<K[rt]?Delete(L[rt],v):Delete(R[rt],v);
	level(rt,v>K[rt]);
	return Del;
}
int GetMax(int rt){return R[rt]?GetMax(R[rt]):rt;}
int Succ(int rt,int y){//求后继 
	if(!rt) return 0;
	if(K[rt]<=y) return Succ(R[rt],y);
	int D=Succ(L[rt],y);
	return D?D:rt;
}
//非递归线段树 
int Max[maxn<<2],N;
void Build(int n){
	N=1;while(N < n+2) N <<=1;
	memset(Max,-1,sizeof(Max));
}
void Add(int X,int V){
	Insert(SBT[X],V);
	for(int s=N+X;s;s>>=1){
		if(V > Max[s]) Max[s]=V;
		else break;
	}
}
void Remove(int X,int V){
	Delete(SBT[X],V);
	if(V < Max[N+X]) return;
	int rt=GetMax(SBT[X]);
	Max[N+X]=K[rt];
	for(int s=(N+X)>>1;s;s>>=1){
		if(Max[s]==V){
			if(Max[s<<1]>=Max[s<<1|1]) Max[s]=Max[s<<1];
			else Max[s]=Max[s<<1|1];
		}
		else break;
	}
}
int Query(int X,int y){
	int s;
	for(s=N+X;s^1;s>>=1){//从左往右搜索子区间 
		if(~s&1&&Max[s^1]>y) break;
	}
	s=s^1;
	if(!s) return 0;
	while(s <N){//在s成为叶节点之前，往下找 
		if(Max[s<<1]>y) s<<=1;
		else s=s<<1|1;
	}
	return s-N;
}
//离散化 
int Rank[maxn],Rn;
void SetRank(){
	int I=1;
	sort(Rank+1,Rank+Rn+1);
	for(int i=2;i<=Rn;++i) if(Rank[i]!=Rank[i-1]) Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int V){
	int L=1,R=Rn;//[L,R] first >=V
	while(L^R){
		int M=(L+R)>>1;
		if(Rank[M] < V) L=M+1;
		else R=M;
	}
	return L;
}
//操作 
int n;
char op[maxn][7];
int X[maxn],Y[maxn];
int main(void)
{
	freopen("19D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		Rn=0;
		for(int i=1;i<=n;++i){
			scanf("%s%d%d",op[i],&X[i],&Y[i]);
			Rank[++Rn]=X[i];
		}
		//离散化 
		SetRank();
		//建树 
		Build(Rn);
		//初始化SBT 
		L[0]=R[0]=S[0]=IP=0;K[0]=-1;
		memset(SBT,0,sizeof(SBT));
		//开始操作 
		for(int i=1;i<=n;++i){
			if(op[i][0]=='a') Add(GetRank(X[i]),Y[i]);//加入点 
			else if(op[i][0]=='r') Remove(GetRank(X[i]),Y[i]);//删除点 
			else{
				int x=Query(GetRank(X[i]),Y[i]);//求横坐标 
				if(x){
					int rt=Succ(SBT[x],Y[i]);//求Y[i]的后继
					printf("%d %d\n",Rank[x],K[rt]);
				}
				else printf("-1\n");
			}
		}
	}
return 0;
}
