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
	int child;
	void init(){
		List=NULL;d=-1;child=-1;
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
	//if(~node[i].d) return;
	ArcNode *temp=node[i].List;
	node[i].d=1;
	//printf("%d:",i+1);
	while(temp){
		 //printf("->%d\n",temp->to+1);
		DFS(temp->to);
		if(node[temp->to].d+1>node[i].d) node[i].d=node[temp->to].d+1,node[i].child=temp->to;
		temp=temp->next;
	}
}
int Vic=0;
void DFS2(int i,int target,int depth){
	if(i==target){
		Vic=1;
		return;
	}
	node[i].d=depth;
	ArcNode *temp=node[i].List;
	while(temp){
		if(!~node[temp->to].d||temp->to==target) {
			node[temp->to].child=i;
			DFS2(temp->to,target,depth+1); 
			
		}
		temp=temp->next;
	}
	//if(!Vic) node[i].d=-1;
}
int END;
int F(int i){
	if(~node[i].child) return F(node[i].child);
	else return i; 
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
		
		
		
		int ANS1=-1,ANS1N,ANS2=-1,ANS2N;
		ArcNode *temp=node[0].List;
		while(temp){
			//OUT2(temp->to+1,node[temp->to].d); 
			if(!~ANS1){
				ANS1=node[temp->to].d;ANS1N=temp->to;
			}
			else if(!~ANS2){
				ANS2=node[temp->to].d;ANS2N=temp->to;
			}else if(node[temp->to].d>ANS1){
				ANS2=ANS1;ANS2N=ANS1N;ANS1=node[temp->to].d;ANS1N=temp->to;
			}
			else if(node[temp->to].d>ANS2) ANS2=node[temp->to].d,ANS2N=temp->to;
			temp=temp->next;
		}
		
		
		int Final=-1,ALL=-1;  int ANS=-1;
		//OUT2(ANS1,ANS2);
		if(!~ANS2) {
			Final=0,ALL=node[0].d;END=F(ANS1N);//OUT1(END);
		}
		else{
			ALL=ANS1+ANS2+1;
			Final=F(ANS1N);END=F(ANS2N);
			OUT2(Final,END);
		}
		//OUT1(ALL);
		For(i,N) node[i].d=-1;
		DFS2(Final,END,1);
		if(ALL&1){
			int k=END;
			For(i,ALL/2) {
				k=node[k].child;
			}
			cout<<k+1<<endl;
		}
		else{
			int k=END;
			For(i,ALL/2-1) {
				k=node[k].child;
			}
			cout<<k+1<<" "<<node[k].child+1<<endl;
		}
		
		
		//int k=END;
		//FOR(i,ALL-1){
		//	printf("%d ",k+1);
		//	k=node[k].child;
		//}
		//if(ALL&1) printf(" %d",k+1);
		//cout<<endl;
		
	}
	
return 0;
}








