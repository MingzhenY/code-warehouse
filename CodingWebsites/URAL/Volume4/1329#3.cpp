#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int N,L;
struct ArcNode{
	int to;
	ArcNode*next;
};
struct Question{
	int a,b;
	bool Ta,Tb;//记录是否包含另一个.
	int TimeOn;//1表示先碰到 a ， 2表示先碰到  b  0表示未碰到或时间已过 
}Q[40001];
struct Node{
	ArcNode*List;
	ArcNode*QList;
}node[40001];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void Arc2(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].QList;
	node[from].QList=temp;
}
void dfs(int rt){
	ArcNode*temp=node[rt].QList;
	while(temp){
		if(Q[temp->to].TimeOn){
			if(Q[temp->to].TimeOn==1&&rt==Q[temp->to].b) Q[temp->to].Ta=1;
			if(Q[temp->to].TimeOn==2&&rt==Q[temp->to].a) Q[temp->to].Tb=1;  
		}
		else{
			if(rt==Q[temp->to].a) Q[temp->to].TimeOn=1;
			if(rt==Q[temp->to].b) Q[temp->to].TimeOn=2;
		}
		temp=temp->next;
	}
	temp=node[rt].List;
	while(temp){
		dfs(temp->to);
		temp=temp->next;
	}
	temp=node[rt].QList;
	while(temp){
		Q[temp->to].TimeOn=0;
		temp=temp->next;
	}
}
int main(void)
{freopen("1329.txt","r",stdin); 
	while(cin>>N){
		int a,b;
		FOR(i,40000) node[i].List=NULL,node[i].QList=NULL;
		int rt=-1;
		//建树 
		For(i,N){
			scanf("%d%d",&a,&b);
			if(!~b) rt=a;
			else Arc(b,a); 	
		}
		cin>>L;
		//记录问题 
		For(i,L){
			scanf("%d%d",&Q[i].a,&Q[i].b);
			Arc2(Q[i].a,i);
			Arc2(Q[i].b,i);
			Q[i].TimeOn=0;
		}
		//求解 
		dfs(rt);
		//输出 
		For(i,L){
			printf("%d\n",(int)Q[i].Ta+(int)Q[i].Tb*2);
		}
	}
return 0;
}








