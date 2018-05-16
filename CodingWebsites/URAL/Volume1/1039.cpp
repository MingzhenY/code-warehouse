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
	int v;
	int In,Out;
	ArcNode *List; 
}node[6000];
void Arc(int from,int to){
	ArcNode  *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
int cross[6000];
int N;
void DFS(int i){
	ArcNode *temp=node[i].List;
	node[i].In=node[i].v;node[i].Out=0;
	while(temp){
		DFS(temp->to);
		node[i].In+=node[temp->to].Out;
		node[i].Out+=max(node[temp->to].In,node[temp->to].Out);
		temp=temp->next;
	}
}
int main(void)
{freopen("1039.txt","r",stdin); 
	while(cin>>N){
		OUT1(sizeof(Node));
		memset(cross,0,sizeof(cross));
		For(i,N) node[i].List=NULL;
		For(i,N) scanf("%d",&node[i].v);
		//½¨Í¼ 
		For(i,N) {
			int a,b;
			scanf("%d%d",&a,&b);a--,b--;
			Arc(b,a);
			cross[a]=1;
		}
		//²âÊÔ
		/*
		For(i,N){
			printf("%d:",i+1);
			ArcNode *temp=node[i].List;
			while(temp){
				printf("->%d",temp->to+1);
				temp=temp->next;
			}
			cout<<endl;
		} 
		*/
		//¼ÆËã 
		int Rt=-1;
		For(i,N) if(!cross[i]) Rt=i;
		DFS(Rt);
		int ANS=max(node[Rt].In,node[Rt].Out);
		cout<<ANS<<endl;
		//ÊÍ·Å
		For(i,N){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		} 
	}
	
return 0;
}








