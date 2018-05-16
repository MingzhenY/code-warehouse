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
	int match;
	ArcNode *List;
	Node(){
		List=NULL;
	} 
}node[2000];
bool vis[2000];
int M,N,K;
void DArc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to+M;
	temp->next=node[from].List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;
	temp->next=node[M+to].List;
	node[M+to].List=temp;
}

bool DFS(int i){
	ArcNode*temp;
	temp=node[i].List;
	while(temp){
		if(!vis[temp->to]){//若未查找过
			vis[temp->to]=1;
			if(!~node[temp->to].match||DFS(node[temp->to].match)){//不在匹配中，或在但是有增广路径 
				node[temp->to].match=i;
				node[i].match=temp->to;
				return 1;
			}	
		}
		temp=temp->next;
	}
	return 0;
}
int MaxMatch(){
	int Sum=0;
	FOR(i,M+N) node[i].match=-1;
	FOR(i,M+N){
		memset(vis,0,sizeof(vis));
		if(DFS(i)){
			Sum++;
		}
	}
	return Sum;
}
int main(void)
{freopen("1109.txt","r",stdin); 
	while(cin>>M>>N>>K){
		//读取 
		For(i,K){
			int from,to;
			scanf("%d%d",&from,&to);
			DArc(from,to);
		}
		//显示 
		/*
		FOR(i,M+N){
			if(i==M+1) printf("右侧开始：\n");
			ArcNode*temp=node[i].List;
			printf("%d:",i>M?i-M:i);
			while(temp){
				printf("->%d",temp->to>M?temp->to-M:temp->to);
				temp=temp->next;
			}
			cout<<endl;
		}*/
		//计算 
		int ANS=MaxMatch();
		
		cout<<ANS<<endl;
		//释放 
		FOR(i,M+N){
			//OUT2(i>M?i-M:i,node[i].match>M?node[i].match-M:node[i].match);
			while(node[i].List){
				ArcNode*temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		}
	}
	
	
	
	
return 0;
}








