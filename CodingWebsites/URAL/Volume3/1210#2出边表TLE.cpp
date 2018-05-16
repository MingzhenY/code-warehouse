#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct ArcNode{
	int to;
	int cost;
	ArcNode *next;
};
struct Node{
	ArcNode *List;
	Node():List(NULL){}
}node[31][30];

void Arc(int from,int to,int cost,int level){
	//printf("from node[%d][%d] to node[%d][%d]\n",level-1,from+1,level,to+1);
	ArcNode *temp=new ArcNode;
	temp->cost=cost;temp->to=to;
	temp->next=node[level-1][from].List;
	node[level-1][from].List=temp;
}
int N;int P[31];
int DFS(int level,int i){
	if(level==N) return 0;
	int ANS=inf;
	ArcNode *temp=node[level][i].List;
	while(temp){
		ANS=min(ANS,temp->cost+DFS(level+1,temp->to));
		temp=temp->next;
	}
	return ANS;
}
int main(void)
{freopen("1210.txt","r",stdin); 
	while(~scanf("%d",&N)){
		//读取 
		//OUT1(N);
		P[0]=1;
		FOR(i,N){
			scanf("%d",&P[i]);
			//OUT2(i,P[i]);
			For(j,P[i]){
				int a,b;
				while(scanf("%d",&a)&&a){
					scanf("%d",&b);
					//OUT2(a,b);
					Arc(a-1,j,b,i);
				}
			}
			if(i<N) scanf(" %*c");
		}/*
		For(i,N){
			printf("等级%d：\n",i);
			For(j,P[i]){
				printf("\t星球%d:",j+1);
				ArcNode *temp=node[i][j].List;
				while(temp){
					printf("->%d",temp->to+1);
					temp=temp->next;
				} 
				cout<<endl;
			}
		}*/
		//计算
		int ANS=DFS(0,0);
		cout<<ANS<<endl;
		For(i,N+1){
			For(j,P[i]){
				while(node[i][j].List){
					ArcNode *temp=node[i][j].List;
					node[i][j].List=node[i][j].List->next;
					delete temp;
				}
			}
		}
	}

return 0;
}








