#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <list>
#include <bitset>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int n,m,q;
//位图结构 
typedef  bitset<1000> Bitmap;

Bitmap PrimeBit;//用来存放质数的位图 

void SetPrimeBit(){//筛法求质数，得到质数位图PrimeBit (只包含小于m的质数) 
	int p[1001];
	memset(p,-1,sizeof(p));
	PrimeBit.reset();
	for(int i=2;i<m;++i){
		if(~p[i]) continue;
		PrimeBit.set(i);
		for(int j=i;j<m;j+=i) p[j]=i;
	}
}
//出边表，偷懒用了List 
list<int> List[maxn];
//第i个节点的价值为V[i]，树链剖分后对应在数组中的下标为 [ L[i],R[i] ] 
//IP是用于树链剖分的一个计数器，对于数组Q的解释：Q[L[i]]=V[i] 
int V[maxn],L[maxn],R[maxn],IP,Q[maxn];
//下面四项用于树链剖分，其实就是一个DFS，  手写了一个栈 
list<int>::iterator S[maxn];
int T[maxn], SP;//T[]记录栈中对应的节点编号,SP栈顶指针 
bool vis[maxn];//visit数组，记录是否已经访问 
void F(int rt){//DFS-树链剖分 
	memset(vis,0,sizeof(vis));
	IP=SP=0;
	S[++SP]=List[rt].begin();
	T[SP]=rt;
	L[rt]=++IP;
	Q[IP]=V[rt]%m;
	vis[rt]=1;
	while(SP>0){
		if(S[SP]!=List[T[SP]].end()){
			rt = *(S[SP]++);
			if(vis[rt]) continue;
			else vis[rt]=1;
			S[++SP]=List[rt].begin();
			T[SP]=rt;
			L[rt]=++IP;
			Q[IP]=V[rt]%m;
		}
		else{
			R[T[SP]]=IP;
			--SP;
		}
	}
}

//线段树 
Bitmap bm[maxn<<2];//线段树的位图 
int Rotate[maxn<<2];//线段树循环位移位数 

//下面是标准的线段树区间修改 
void PushUp(int rt){//更新信息 
	bm[rt]=bm[rt<<1]|bm[rt<<1|1];
}
void PushDown(int rt){//下推标记 
	if(Rotate[rt]){
		Rotate[rt<<1]=(Rotate[rt<<1]+Rotate[rt])%m;
		Rotate[rt<<1|1]=(Rotate[rt<<1|1]+Rotate[rt])%m;
		bm[rt<<1]=(bm[rt<<1]<<Rotate[rt])|(bm[rt<<1]>>(m-Rotate[rt]));
		bm[rt<<1|1]=(bm[rt<<1|1]<<Rotate[rt])|(bm[rt<<1|1]>>(m-Rotate[rt]));
		Rotate[rt]=0;
	}
}
void Build(int l,int r,int rt){//建树 
	if(l==r){
		bm[rt].reset();
		bm[rt].set(Q[l]%m);
		Rotate[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	Build(ls);
	Build(rs);
	PushUp(rt);
}
void Update(int L,int R,int X,int l,int r,int rt){//区间位图循环移位 
	if(L <= l && r <= R){
		Rotate[rt]=(Rotate[rt]+X)%m;
		X%=m;
		bm[rt]=(bm[rt]<<X)|(bm[rt]>>(m-X));
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <= m) Update(L,R,X,ls);
	if(R >  m) Update(L,R,X,rs);
	PushUp(rt);
}
Bitmap Query(int L,int R,int l,int r,int rt){//查询区间位图相与 
	if(L <= l && r <= R){
		return bm[rt];
	}
	PushDown(rt);
	int m=(l+r)>>1;
	Bitmap ANS;
	if(L <= m) ANS = ANS | Query(L,R,ls);
	if(R >  m) ANS = ANS | Query(L,R,rs);
	return ANS;
} 

int main(void)
{
	freopen("633G.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		//计算质数位图 
		SetPrimeBit();
		//初始化+读取数据 
		for(int i=1;i<=n;++i) List[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&V[i]);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b); 
			List[a].push_back(b);
			List[b].push_back(a); 
		}
		//树链剖分  
		F(1);
		
		//线段树建树 
		Build(1,n,1);
		
		//读取询问 
		scanf("%d",&q);
		for(int i=0;i<q;++i){
			int op,v,x;
			scanf("%d%d",&op,&v);
			if(op==1){
				scanf("%d",&x);
				//线段树区间修改 
				Update(L[v],R[v],x%m,1,n,1);
			}
			else{
				//线段树区间查询 
				printf("%d\n",(Query(L[v],R[v],1,n,1)&PrimeBit).count());
			}
		}
	}
return 0;
}

