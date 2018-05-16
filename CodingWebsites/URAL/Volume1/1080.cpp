#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
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
	int color;
	ArcNode *List;
}node[101];
void DArc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	
	temp=new (ArcNode);
	temp->to=from;
	temp->next=node[to].List;
	node[to].List=temp; 
}
int N;int ERR;
void DFS(int i,int color); 
int main(void)
{freopen("1080.txt","r",stdin); 
	cin>>N;
	//建边 
	for(int i=0;i<N;i++){
		node[i].List=NULL;
	}
	for(int i=0;i<N;i++){	
		int a;scanf("%d",&a);
		while(a){
			DArc(i,a-1);
			scanf("%d",&a);
		}
		node[i].color=-1;//未上色
	}
	ERR=0;//未出错 
	
	for(int i=0;i<N;i++){
		if(!~node[i].color) DFS(i,0);
	}
	
	if(ERR){
		cout<<-1<<endl;
	}
	else{
		for(int i=0;i<N;i++){
			printf("%c",node[i].color+48);
		}
		cout<<endl;
	}
	//释放
	for(int i=0;i<N;i++){
		while(node[i].List){
			ArcNode *temp=node[i].List;
			node[i].List=node[i].List->next;
			delete temp;
		}
	} 
	
return 0;
}
void DFS(int i,int color){
	if(~node[i].color){
		if(color!=node[i].color) ERR=1;
		return;
	}
	else node[i].color=color;
	ArcNode *temp=node[i].List;
	while(temp){
		DFS(temp->to,1-color);  
		temp=temp->next;
	}
}







