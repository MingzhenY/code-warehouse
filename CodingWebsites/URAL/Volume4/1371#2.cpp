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
	long long D;
	ArcNode*next;
};
struct Node{
	bool vis;
	ArcNode*List;
	Node():vis(0),List(NULL){}
}node[50000];
void Arc(int from,int to,int value){
	ArcNode*temp=new ArcNode;
	temp->to=to;temp->v=value;temp->D=0;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to,int value){
	Arc(from,to,value);Arc(to,from,value);
}
int n;double ALL;
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
		ALL+=(temp->D)*(n-temp->D)*(temp->v);
		temp=temp->next;
	}
	return ANS+1;
}
int main(void)
{freopen("1371.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<n-1;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			DArc(a-1,b-1,v);
		}
		ALL=0.0;
		Dfs(0);
		ALL/=(long long) n*(n-1)/2;
		printf("%f\n",ALL);
		for(int i=0;i<n;++i){
			node[i].vis=0;
			while(node[i].List){
				ArcNode*temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		}
	}
return 0;
}








