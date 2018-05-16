
/*
用最小生成树的思想。
每次加入一条边，如果边连接的两点已经相连，则形成了一个环，找到这个环并输出，不加入这条边。
如果两点不相连，则加入这条边。 

相连部分永远保持为一棵树（或几棵树）。所以从起点找终点的DFS就很好写了 
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
//图 
struct ArcNode{
	int from,to;
	ArcNode *next;
}Arc[40000];
struct Node{
	bool vis;
	int path;
	ArcNode *List;
	void init(){vis=0;List=NULL;path=-1;}
}node[200];
void AddArc(int i){
	Arc[2*i].next=node[Arc[2*i].from].List;
	node[Arc[2*i].from].List=&Arc[2*i];
	Arc[2*i+1].next=node[Arc[2*i+1].from].List;
	node[Arc[2*i+1].from].List=&Arc[2*i+1];
	
}
void MinusArc(int i){
	node[Arc[2*i].from].List=node[Arc[2*i].from].List->next;
	node[Arc[2*i+1].from].List=node[Arc[2*i+1].from].List->next;
}
int N,M,ALL;//点，边 
//并查集 
int U[200];
int Find(int x){
	if(x==U[x]) return x;
	else return U[x]=Find(U[x]);
}
void Union(int x,int y){
	//printf("连接%d与%d\n",x+1,y+1);
	int a=Find(x),b=Find(y);
	if(a!=b) U[a]=b,ALL--;
}
//
void DFS(int i,int depth,int target){
	//OUT2(i+1,depth);
	//For(t,depth) printf("  ");
	//printf("->%d\n",i+1);
	if(i==target){
		int k=i;
		printf("%d",depth);
		For(j,depth){
			printf(" %d",k+1);
			k=node[k].path;
		}
		cout<<endl;
		return;
	}
	node[i].vis=1;
	ArcNode *temp=node[i].List;
	while(temp){
		if(!node[temp->to].vis||temp->to==target){			
			node[temp->to].path=i;
			DFS(temp->to,depth+1,target);
		}				
		temp=temp->next;
	}
}
int main(void)
{
freopen("1077.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,N) {
			node[i].init();
			U[i]=i;
		}
		//读取
		ALL=N;
		For(i,M){
			scanf("%d%d",&Arc[2*i].from,&Arc[2*i].to);
			Arc[2*i].from--;Arc[2*i].to--;
			Arc[2*i+1].from=Arc[2*i].to;Arc[2*i+1].to=Arc[2*i].from;
			AddArc(i);
			Union(Arc[2*i].from,Arc[2*i].to);			
		}
		cout<<M-N+ALL<<endl;
		For(i,N) U[i]=i,node[i].List=NULL;
		For(i,M) Arc[2*i].next=NULL,Arc[2*i+1].next=NULL;
		
		For(i,M){
			//printf("第%d条边\n",i+1);
			int a=Find(Arc[2*i].from),b=Find(Arc[2*i].to);
						
			if(a==b){
				//找环(找from到to的路径)
				//printf("\t起点：%d 终点 :%d \n",Arc[2*i].from+1,Arc[2*i].to+1);
				DFS(Arc[2*i].from,1,Arc[2*i].to);
				For(j,N) node[j].vis=0;
			}
			else{
				AddArc(i);
				Union(Arc[2*i].from,Arc[2*i].to);
			}
		}
	}
return 0;
}








