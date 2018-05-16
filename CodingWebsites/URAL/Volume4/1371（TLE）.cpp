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
struct ArcNode{
	int to,v;
	int D;
	ArcNode*next;
};
struct Node{
	bool vis;
	ArcNode*List;
	Node():vis(0),List(NULL){}
}node[50000];
void Arc(int from,int to,int value){
	ArcNode*temp=new ArcNode;
	temp->to=to;temp->v=value;temp->D=-1;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to,int value){
	Arc(from,to,value);Arc(to,from,value);
}
int n;
void exDfs(int to,int from,int value){
	ArcNode*temp=node[to].List;
	while(temp){
		if(temp->to==from){
			temp->D=value;
			return; 
		}
		temp=temp->next;
	} 
}
int Dfs(int k){
	ArcNode*temp=node[k].List;
	node[k].vis=1;int ANS=0;
	while(temp){
		if(!node[temp->to].vis){
			temp->D=Dfs(temp->to);
			ANS+=temp->D;
		}
		temp=temp->next;
	}
	temp=node[k].List;
	while(temp){
		exDfs(temp->to,k,n-temp->D);
		temp=temp->next;
	}
	return ANS+1;
}
double ALL;
void exdfs2(int to,int from,int D){
	ArcNode*temp=node[to].List;
	while(temp){
		if(temp->to==from){
			//OUT3(to,from,D*(temp->D)*(temp->v));
			ALL+=D*(temp->D)*(temp->v);
			return;
		}
		temp=temp->next;
	}
}
void dfs2(int k){
	ArcNode*temp=node[k].List;
	node[k].vis=1;
	while(temp){
		if(!node[temp->to].vis) {
			exdfs2(temp->to,k,temp->D);
			dfs2(temp->to);
		}
		temp=temp->next;
	} 
} 
int main(void)
{freopen("1371.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<n-1;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			DArc(a-1,b-1,v);
		}
		Dfs(0);
		for(int i=0;i<n;i++) node[i].vis=0;
		ALL=0.0;
		dfs2(0);
		ALL/=n*(n-1)/2;
		printf("%.4f\n",ALL);
		for(int i=0;i<n;++i){
			node[i].vis=0;//OUT1(i);
			while(node[i].List){
				ArcNode*temp=node[i].List;
				//OUT2(temp->to,temp->D);
				node[i].List=node[i].List->next;
				delete temp;
			}
		}
	}
return 0;
}








