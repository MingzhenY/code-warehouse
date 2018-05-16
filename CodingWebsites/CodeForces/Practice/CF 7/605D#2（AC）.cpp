/*
	本质上是一个广度优先搜索
	选择下一个可选的向量时，需要用数据结构来加快查找 
	这里使用了 线段树套SBT 来实现 
	其中线段树结合了递归和非递归的代码，查询部分是递归的，更新最小值部分是非递归的。 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cstring>
#define INF 1000000007
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define OUT4(a1,a2,a3,a4) cout out(a1) out(a2) out(a3) out(a4)<<endl
using namespace std;
//离散化
int Rank[maxn],Rn;
void SetRank(int n){
	sort(Rank+1,Rank+n+1);
	Rn=1;
	for(int i=2;i<=n;++i)
		if(Rank[i]!=Rank[i-1]) 
			Rank[++Rn]=Rank[i];
}
int GetRank(int x){
	int L=1,R=Rn;//[L,R]
	while(L^R){
		int M=(L+R)>>1;
		if(Rank[M] < x) L=M+1;
		else R=M;
	}
	return L;
}
//SBT
int L[maxn],R[maxn],S[maxn],IP;
struct Node{
	int y,id;
	Node(int y=0,int id=0):y(y),id(id){}
	bool operator <(const Node &B)const{return y < B.y||y==B.y&&id < B.id;}
	bool operator ==(const Node &B)const{return y==B.y&&id==B.id;}
}K[maxn];
void InitSBT(){L[0]=R[0]=S[0]=IP=0;}
void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;} 
void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void level(int &x,bool flag){
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
void Insert(int &rt,Node v){
	if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=v;return;}
	++S[rt];
	v < K[rt]?Insert(L[rt],v):Insert(R[rt],v);
	level(rt,v < K[rt]);
}
Node GetLeft(int &rt){
	return L[rt]?GetLeft(L[rt]):K[rt];
}
Node Delete(int &rt,Node v){
	Node Del;
	--S[rt];
	if(v==K[rt]||v<K[rt]&&!L[rt]||K[rt]<v&&!R[rt]){
		Del=K[rt];
		if(!L[rt]||!R[rt]) rt=L[rt]+R[rt];
		else K[rt]=Delete(L[rt],v);
	}
	else Del=v<K[rt]?Delete(L[rt],v):Delete(R[rt],v);
	level(rt,K[rt]<v);
	return Del;
}
void ShowSBT(int rt,string prefix){
	if(!rt) return;
	cout<<prefix<<K[rt].y<<endl;
	ShowSBT(L[rt],prefix+"    ");
	ShowSBT(R[rt],prefix+"    ");
}
//线段树
int N; 
int Miny[maxn<<2];//最小y值
int SBT[maxn];//每个叶节点都是SBT
void Build(int n){
	N=1;while(N < n+2) N<<=1;
	for(int i=1;i<=n;++i) SBT[i]=0;
	for(int i=N;i<2*N;++i) Miny[i]=INF;
	for(int i=N-1;i>0;--i) Miny[i]=INF;
}
void Update(int x,int y,int id){
	Insert(SBT[x],Node(y,id));
	int snt = SBT[x]?GetLeft(SBT[x]).y:INF;
	for(int t=N+x;t;t>>=1) 
		if(snt < Miny[t]) Miny[t]=snt;
		else break;
}
int Query(int Y,int l,int r,int rt){//找最小x 使得 y 小于等于 Y 
	if(l==r){
		return l-1;
	}
	int m=(l+r)>>1;
	if(Miny[rt<<1]<=Y) return Query(Y,ls);
	else return Query(Y,rs);
}
void DelUpdate(int x){
	Miny[N+x] = SBT[x]?GetLeft(SBT[x]).y:INF;
	for(int t=N+x;t>>=1;) Miny[t]=min(Miny[t<<1],Miny[t<<1|1]);
}
void ShowST(){
	for(int i=1;i<=Rn;++i) {
		OUT4(i,Rank[i],S[SBT[i]],Miny[N+i]);
		ShowSBT(SBT[i],"");
	}
}
//题目信息 
int n;
int x[maxn],y[maxn],c[maxn],d[maxn];
queue<int> B;
int D[maxn];
int Pre[maxn];

void Show(int x){
	if(!x) return;
	Show(Pre[x]);
	printf("%d ",x);
} 
int main(void)
{
	freopen("605D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		while(!B.empty()) B.pop();
		memset(D,-1,sizeof(D));
		InitSBT();
		for(int i=1;i<=n;++i){
			scanf("%d%d%d%d",&x[i],&y[i],&c[i],&d[i]);
			Rank[i]=x[i];
			if(!(x[i]||y[i])) {//加入起始向量 
				D[i]=1;
				Pre[i]=0;
				B.push(i);
			}
		}
		SetRank(n);
		Build(Rn);
		for(int i=1;i<=n;++i) if(x[i]||y[i]) Update(GetRank(x[i]),y[i],i);
		while(!B.empty()){//BFS的队列 
			int cnt=B.front();B.pop();
			while(Miny[1]<=d[cnt]){//存在y小于当前y 
				int X=Query(d[cnt],1,N,1);//找到y小于当前y对应的最小x 
				if(Rank[X] > c[cnt]) break;//如果x大于当前x，退出 
				//找到可选向量，更新信息加入队列 
				Node T=GetLeft(SBT[X]);
				Delete(SBT[X],T);
				DelUpdate(X);
				B.push(T.id);
				D[T.id]=D[cnt]+1;
				Pre[T.id]=cnt;
			}
		}
		printf("%d\n",D[n]);
		if(~D[n]){
			Show(Pre[n]);
			printf("%d\n",n);
		}
	}
return 0;
}

