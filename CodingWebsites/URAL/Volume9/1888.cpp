#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 51
using namespace std;

//并查集 
int f[maxn],v[maxn];int U;//U 联通分量 
int Find(int x){
	int tempv=0,a=x;
	while(a!=f[a]) tempv^=v[a],a=f[a];
	f[x]=a;v[x]=tempv;return a;
}
int ERR,Dif;
void Union(int x,int y,int V){
	int a=Find(x),b=Find(y);
	if(a==b){if(v[x]^v[y]==0) ERR=1;}
	else{f[a]=b;v[a]=V^v[x]^v[y];--U;}
}
//图一 
int n,p;
struct ArcNode{
	int to;
	ArcNode *next;
}; 
struct Node{
	ArcNode *List;
	int year;
	int vis;
	void init(){year=vis=0;List=NULL;}
}node[maxn];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to){Arc(from,to);Arc(to,from);}
//图二
int A[maxn][maxn]; 
int path[maxn][maxn];
int Lpath[maxn],nLpath;
//DFS连通块染色
void D_Low(int t){
	ArcNode *temp=node[t].List;
	while(temp){
		if(!node[temp->to].vis){
			node[temp->to].vis=1;
			node[temp->to].year=3-node[t].year;
			D_Low(temp->to);
		}
		temp=temp->next;
	}
} 
void D_High(int t){
	ArcNode *temp=node[t].List;
	while(temp){
		if(!node[temp->to].vis){
			node[temp->to].vis=1;
			node[temp->to].year=99-node[t].year;
			D_High(temp->to);
		}
		temp=temp->next;
	}
} 
int main(void)
{freopen("1888.txt","r",stdin); 
	while(~scanf("%d%d",&n,&p)){
		//初始化
		for(int i=1;i<=p;++i) f[i]=i,v[i]=0,node[i].init();
		for(int i=1;i<=p;++i) for(int j=1;j<=p;++j) A[i][j]=i==j?0:inf,path[i][j]=i;
		ERR=0;U=p;
		//建图 
		for(int i=0;i<n;++i){
			int a,b;scanf("%d%d",&a,&b);
			Union(a,b,1);DArc(a,b);
			A[a][b]=A[b][a]=1;
		}
		if(!ERR){
			if(U==1) {//计算 
				//Floyd
				for(int k=1;k<=p;++k){
					for(int i=1;i<=p;++i){
						for(int j=1;j<=p;++j){
							if(A[i][k]+A[k][j]<A[i][j]){
								A[i][j]=A[i][k]+A[k][j];
								path[i][j]=path[k][j];
							}
						}
					}
				}
				//求出最长的一条最短路
				int From,To,Max=0; 
				for(int i=1;i<=p;++i){
					for(int j=1;j<=p;++j){
						if(A[i][j]!=inf&&A[i][j]>Max){							
							From=i;To=j;Max=A[i][j];
						}
					}
				}
				Dif=A[From][To];
				//记录最长路径
				nLpath=0;
				while(path[From][To]!=From){
					Lpath[++nLpath]=To;
					To=path[From][To];
				}
				Lpath[++nLpath]=To;
				Lpath[++nLpath]=From;
				//建立最长路上的year 
				for(int i=1;i<=nLpath;++i){
					node[Lpath[i]].year=i;
				}
				//填补其他空白
				for(int i=1;i<=p;++i){
					if(!node[i].year){
						int L=-1,R=-1;
						ArcNode *temp=node[i].List;
						while(temp){
							if(node[temp->to].year){
								if(!~L) L=temp->to;
								else{
									if(L!=temp->to){
										if(!~R){R=temp->to;}
										else{if(temp->to!=R) ERR=1;}
									}
								}	
							}
							temp=temp->next;
						}
						if(!~R){node[i].year=L-1;}
						else{node[i].year=(L+R)>>1;}
					}
				} 
			}
			else{
				int count=0;
				for(int i=1;i<=p;++i){
					if(f[i]==i){
						count++;node[i].vis=1;
						if(count&1) node[i].year=1,D_Low(i);
						else node[i].year=50,D_High(i);
					}
				}
				Dif=49;
			} 
		}
		if(ERR) printf("-1\n");
		else{
			printf("%d\n",Dif);
			for(int i=1;i<=p;++i){
				printf("%d",node[i].year);
				if(i==p) printf("\n");
				else printf(" ");
			}
		}
	}
return 0;
}








