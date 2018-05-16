#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define maxn 202
#define inf 0x7fffffff
using namespace std;
int n;
int a[201];
bool isprime[20001];
struct Edge{
	int from,to,cap,flow;
	Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
};
struct ArcNode{
	int from,to;
	ArcNode *next;
};
struct A{
	ArcNode *List;
	A():List(NULL){}
	void ADD(int from,int to){
		ArcNode *temp=new ArcNode;
		temp->from=from;temp->to=to;
		temp->next=List;
		List=temp;
	}
	bool FIND(int from,int to){
		ArcNode *temp=List;
		while(temp){
			if(temp->from==from&&temp->to==to) return true;
			temp=temp->next;
		}
		return false;
	}
	void DEL(int from,int to){
		ArcNode *NewList=NULL;
		while(List){
			ArcNode *temp=List;
			List=List->next;
			if(temp->from==from&&temp->to==to) delete temp;
			else{
				temp->next=NewList;
				NewList=temp;
			}
		}
		List=NewList;
	}
	void Clear(){
		while(List){
			ArcNode *temp=List;
			List=List->next;
			delete temp;
		}
	}
}X;
int f[202];
int v[202];
struct Dinic{
	int m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	void AddEdge(int from,int to,int cap){
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	void clear(){
		edges.clear();
		for(int i=0;i<maxn;++i) G[i].clear();
		memset(vis,0,sizeof(vis));
	}
	void dfs(int i,vector<int> &V){
		vis[i]=1;V.push_back(i);
		int nextL=0,nextR=0;
		if(edges[G[i][0]].from==i) nextL=edges[G[i][0]].to;
		else nextL=edges[G[i][0]].from;
		if(edges[G[i][1]].from==i) nextR=edges[G[i][1]].to;
		else nextR=edges[G[i][1]].from;
		//printf("G[%d][0]=%d G[%d][1]=%d\n",i,G[i][0],i,G[i][1]);
		if(!vis[nextL]) dfs(nextL,V);
		else if(!vis[nextR]) dfs(nextR,V);
	}
	bool BFS(){
		memset(vis,0,sizeof(vis));
		queue<int>Q;
		Q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			for(int i=0;i<G[x].size();i++){
				Edge &e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int DFS(int x,int a){
		if(x==t||a==0) return a;
		int flow=0,f;
		for(int &i=cur[x];i<G[x].size();i++){
			Edge &e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
				
				if(e.from>=1&&e.from <=n&&e.to>=1&&e.to <=n){
					//printf("(%d,%d)\n",::a[e.from],::a[e.to]);
					if(X.FIND(e.to,e.from)) X.DEL(e.to,e.from);
					else X.ADD(e.from,e.to);
				}
				
				//从e.from到e.to多了
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t){
		this->s=s;this->t=t;
		int flow=0;
		while(BFS()){
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,inf);
		}
		return flow;
	}
};


int main(void)
{
	freopen("510E.txt","r",stdin);
	for(int i=2;i<20001;++i) isprime[i]=1;
	for(int i=2;i<20001;++i){
		if(isprime[i]){
			for(int j=i<<1;j<20001;j+=i) isprime[j]=0;
		}
	}
	while(~scanf("%d",&n)){
		//printf("n=%d\n",n);
		//初始化 
		int even=0,odd=0;
		//读取 
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),even+=~a[i]&1,odd+=a[i]&1;
		if(even!=odd) {printf("Impossible\n");continue;}
		//建边 
		Dinic D;
		int EdgeId=0;
		for(int i=1;i<=n;++i){
			if(a[i]&1) D.AddEdge(0,i,2);
			else D.AddEdge(i,n+1,2);
			for(int j=i+1;j<=n;++j){
				if(isprime[a[i]+a[j]]){
					if(a[i]&1)  D.AddEdge(i,j  ,1);
					else   D.AddEdge(j,i  ,1);
				}
			}
		}
		//网络流
		X.Clear();
		int MaxFlow=D.Maxflow(0,n+1);
		vector<int>V[202];int Vn=0;
		if(MaxFlow==odd+even){
			for(int i=1;i<=n;++i) v[i]=0,f[i]=0;
			D.clear();
			ArcNode *temp=X.List;
			while(temp){
				//printf("%d->%d\n",temp->from,temp->to);
				D.AddEdge(temp->from,temp->to,0);
				temp=temp->next;
			} 
			for(int i=1;i<=n;++i){
				if(D.vis[i]) continue;
				D.dfs(i,V[i]);Vn++;
				
			}
			printf("%d\n",Vn);
			for(int i=1;i<=n;++i){
				if(V[i].size()){
					printf("%d",V[i].size());
					for(int k=0;k<V[i].size();k++){
						printf(" %d",V[i][k]);
					}
					printf("\n");
				}
			}
		}
		else{
			printf("Impossible\n");
		}
	}

		
return 0;
}














