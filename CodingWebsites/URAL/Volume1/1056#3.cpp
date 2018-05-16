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
	int to;
	ArcNode *next;
};
struct Node{
	int d;
	ArcNode *List;
	int path;
	void init(){
		List=NULL;d=-1;path=-1;
	} 
}node[10000];
void Arc(int from,int to){
	//OUT2(from,to);
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;
	temp->next=node[to].List;
	node[to].List=temp;	
}
int N;
void DFS(int i){
	ArcNode *temp=node[i].List;
	node[i].d=1;
	//printf("%d:",i+1);
	while(temp){
		 //printf("->%d\n",temp->to+1);
		if(!~node[temp->to].d){
			DFS(temp->to);
			if(node[temp->to].d+1>node[i].d) node[i].d=node[temp->to].d+1,node[i].path=temp->to;
		}
		temp=temp->next;
	}
}
int End;int ALL;
void F(int i){
	if(~node[i].path){
		F(node[i].path);
		//node[node[i].path].path=i;
	}
	else End=i;
	ALL++;
}

int main(void)
{freopen("1056.txt","r",stdin); 
	while(cin>>N){
		For(i,N) node[i].init();
		for(int i=1;i<N;i++){
			int a;
			scanf("%d",&a);
			Arc(a-1,i);
		}
		DFS(0);
		F(0);
		For(i,N) node[i].d=-1,node[i].path=-1;
		int OldEnd=End;ALL=0;
		DFS(OldEnd);F(OldEnd);
		//OUT3(OldEnd,End,ALL);
		int k=OldEnd;int A=-1,B=-1;
		FOR(i,ALL){
			//printf("->%d(%d)",k+1,i);
			if(i==(ALL+1)/2){
				A=k+1; 
				if(!(ALL&1)) B=node[k].path+1;
			}
			k=node[k].path;
		}
		if(~B){
			if(A>B) printf("%d %d\n",B,A);
			else printf("%d %d\n",A,B);
		}
		else printf("%d\n",A);
	}
	
return 0;
}








