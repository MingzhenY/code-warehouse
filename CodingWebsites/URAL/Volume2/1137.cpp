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
	int to;bool vis;
	ArcNode*next;
};
struct Node{
	ArcNode*List;
}node[10000];
void Arc(int from,int to){
	ArcNode*temp;
	temp=new ArcNode;
	temp->to=to;temp->vis=0;
	temp->next=node[from].List;
	node[from].List=temp;
} 
int N;int ALL=0;int Found;
int ArcPath[1000000];
void dfs(int i,int depth){//返回从i开始最深有多少，记录path 
	ArcPath[depth]=i+1;
	if(depth==ALL){
		Found=1;
		return;
	}
	int ANS=0;
	ArcNode*temp=node[i].List;
	while(temp){
		//if(i==3) OUT3(i,temp->to,node[temp->to].vis);
		if(!temp->vis){
			temp->vis=1;
			dfs(temp->to,depth+1);
			if(Found) return;
			temp->vis=0;
		}
		temp=temp->next;
	}
	return ;
}

int main(void)
{freopen("1137.txt","r",stdin); 
	while(cin>>N){
		//输入 
		For(i,10000) node[i].List=NULL;
		ALL=0;
		For(i,N){
			int M,from,to;
			scanf("%d%d",&M,&from);ALL+=M;
			For(j,M){
				scanf("%d",&to);
				Arc(from-1,to-1);
				from=to;
			}
		}
		//计算 
		Found=0;
		For(i,10000){
			dfs(i,1);
			if(Found){
				break;
			}
		}
		if(Found){
			printf("%d",ALL);
			FOR(i,ALL){
				printf(" %d",ArcPath[i]);
			}
			printf(" %d\n",ArcPath[1]);
		}
		else cout<<0<<endl;
		//释放 
		For(i,10000){
			//printf("%d:",i+1);
			while(node[i].List){
				//printf("->%d",node[i].List->to+1); 
				ArcNode*temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp; 
			}//cout<<endl;
		}
	}
return 0;
}








