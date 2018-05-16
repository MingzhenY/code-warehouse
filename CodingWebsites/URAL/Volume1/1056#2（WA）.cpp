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
	int d;//有多少子电脑 
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
}
int N;
void DFS(int i){
	ArcNode *temp=node[i].List;
	node[i].d=1;
	//printf("%d:",i+1);
	while(temp){
		 //printf("->%d\n",temp->to+1);
		DFS(temp->to);
		if(node[temp->to].d+1>node[i].d) node[i].d=node[temp->to].d+1,node[i].path=temp->to;
		temp=temp->next;
	}
}
int END;
void F(int i){
	if(~node[i].path){
		F(node[i].path);
		node[node[i].path].path=i;
	}
	else END=i;
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
		//寻找第二长的路径S2
		int OldPath=node[0].path,S2=-1;
		ArcNode *temp=node[0].List;
		while(temp){
			if(temp->to!=OldPath){
				if(~S2||node[temp->to].d>node[S2].d) S2=temp->to;
			} 
			temp=temp->next;
		}
		//OUT1(S2+1);
		F(0);node[0].path=S2;
		//OUT1(END+1);
		int ALL=0;
		int k=END;
		while(1){
			ALL++;
			//printf("->%d",k+1);
			if(!~node[k].path) break;
			k=node[k].path;
		}
		k=END;
		OUT1(ALL);
		int A=-1,B=-1;
		FOR(i,ALL/2){
			if(i==ALL/2) {
				A=k+1; 
				if(!(ALL&1)) B=node[k].path+1;
			}
			if(!~node[k].path) break;
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








