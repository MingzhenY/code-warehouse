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
int fa[40001];
int N,L;
struct ArcNode{
	int to;
	ArcNode*next;
};
struct Node{
	int level;
	ArcNode*List;
}node[40001];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void F(int rt,int level){
	node[rt].level=level;
	ArcNode *temp=node[rt].List;
	while(temp){
		F(temp->to,level+1);
		temp=temp->next;
	}
}
int main(void)
{freopen("1329.txt","r",stdin); 
	while(cin>>N){
		memset(fa,-1,sizeof(fa));int a,b;
		FOR(i,40000) node[i].List=NULL;
		int rt=-1;
		For(i,N){
			scanf("%d%d",&a,&b);
			fa[a]=b;
			if(!~b) rt=a;
			else Arc(b,a); 	
		}
		if(~rt){
			F(rt,1);
		}
		cin>>L;
		For(i,L){
			scanf("%d%d",&a,&b);int T=0;
			if(node[a].level>node[b].level){
				int t=a;a=b;b=t;T=1;
			}
			int x=b;int ANS=0;
			while(~x&&node[x].level>=node[a].level){
				if(x==a){
					ANS=1;
					break;
				}
				x=fa[x];
			}
			if(ANS){
				printf("%d\n",ANS+T);
			}
			else{
				printf("0\n");
			}
		}
	}
return 0;
}








