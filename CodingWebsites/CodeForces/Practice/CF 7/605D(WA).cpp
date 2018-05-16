/*
	离散化+线段树套优先队列+BFS 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cstring>
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int n;
//离散化x 
int Rank[maxn],Rn;
void SetRank(){
	sort(Rank+1,Rank+n+1);
	int I=1;
	for(int i=2;i<=n;++i)
		if(Rank[i]!=Rank[i-1]) 
			Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=n;//[L,R]
	while(L^R){
		int M=(L+R)>>1;
		if(Rank[M] < x) L=M+1;
		else R=M;
	}
	return L;
}
//线段树
struct Node{
	int y,id;
	Node(int y=0,int id=0):y(y),id(id){}
	bool operator < (const Node &B)const{return y > B.y || y == B.y && id > B.id;}
};
priority_queue<Node> Q[maxn];
int Num[maxn<<2];//数量 
void Build(int l,int r,int rt){
	if(l==r){
		while(!Q[l].empty()) Q[l].pop();
		Num[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	Build(ls);
	Build(rs);
	Num[rt]=Num[rt<<1]+Num[rt<<1|1];
}
void Update(int x,int y,int id,int l,int r,int rt){
	if(l==r){
		Q[l].push(Node(y,id));
		++Num[rt];
		return;
	}
	int m=(l+r)>>1;
	if(x <= m) Update(x,y,id,ls);
	else  	   Update(x,y,id,rs);
	++Num[rt];
}
int Query(int l,int r,int rt){//找最小X 
	if(l==r){
		return l;
	}
	int m=(l+r)>>1;
	if(Num[rt<<1]>0) return Query(ls);
	else return Query(rs);
}
void Del(int X,int l,int r,int rt){
	Num[rt]--;
	if(l==r) return;
	int m=(l+r)>>1;
	if(X <= m) Del(X,ls);
	else Del(X,rs);
}

//题目信息 
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
		for(int i=1;i<=n;++i){
			scanf("%d%d%d%d",&x[i],&y[i],&c[i],&d[i]);
			Rank[i]=x[i];
			if(!(x[i]||y[i])) {
				D[i]=1;
				Pre[i]=0;
				B.push(i);
			}
		}
		SetRank();
		Build(1,Rn,1);
		for(int i=1;i<=n;++i) if(x[i]||y[i]) Update(GetRank(x[i]),y[i],i,1,Rn,1);
		
		while(!B.empty()){
			int cnt=B.front();B.pop();
			OUT1(cnt);
			int X;Node T;
			int temp=1;
			while(Rank[X=Query(1,Rn,1)]<= c[cnt]){
				while(!Q[X].empty()&&(T=Q[X].top()).y <= d[cnt]){
					Q[X].pop();
					Del(X,1,Rn,1);
					temp++;
					D[T.id]=D[cnt]+1;
					Pre[T.id]=cnt;
					B.push(T.id);
					OUT2("Add",T.id);
				}
				if(temp--<0) break;;
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

