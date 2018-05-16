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
	int i;
	int to;
	ArcNode *next;
};
struct Node{
	int vis;
	int path;
	int arc;
	ArcNode *List;
	void init(){
		vis=0;path=-1;List=NULL;arc=-1;
	}
}node[200];int VN; 
void Darc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->i=VN;
	temp->next=node[from].List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;temp->i=VN++;
	temp->next=node[to].List;
	node[to].List=temp;
}
int N,M;

int ans[200][200];int AN;
bool vis[40000];
int ansn[200];
void dfs(int i,int depth); 
int main(void)
{
freopen("1077.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,N) node[i].init();
		memset(vis,0,sizeof(vis));
		//建图 
		VN=0;
		For(i,M){
			int a,b;
			scanf("%d%d",&a,&b);
			Darc(a-1,b-1);
		}
		/*
		//显示 
		For(i,N){
			ArcNode *temp=node[i].List;
			printf("%d:",i+1);
			while(temp){
				printf("->%d",temp->to+1);
				temp=temp->next; 
			}
			cout<<endl;
		}
		*/
		//DFS 
		AN=0;
		
		dfs(0,1);
		printf("%d\n",AN);
		For(i,AN){
			
			printf("%d",ansn[i]);
			
			For(j,ansn[i]) {
				printf(" %d",ans[i][j]+1);
			}
			cout<<endl;
		} 
	}
	
return 0;
}
void dfs(int i,int depth){
	if(node[i].vis){
		if(!i&&(depth>3)){
			
			int T=0;int k=i;ansn[AN]=0;
			For(t,depth-1){
				ans[AN][ansn[AN]++]=k;
				
				if(!vis[node[k].arc]) T=1;
				k=node[k].path;
			}
			if(T){//如果符合条件 
				printf("找到长度为%d的路径：",depth-1) ; 
				AN++;k=i;
				For(t,depth-1){
					printf("->%d",node[k].arc+1);
					vis[node[k].arc]=1;
					k=node[k].path;
				}cout<<endl;
			}
			//cout<<endl;
		}
		return;
	}
	ArcNode *temp=node[i].List;
	node[i].vis=1;
	
	while(temp){
		//For(t,depth) printf("   "); 
		if(!node[temp->to].vis||!temp->to) {
			//For(t,depth) printf("   "); 
			//printf("%d->%d\n",i+1,temp->to+1);
			node[temp->to].path=i;
			node[temp->to].arc=temp->i;
			dfs(temp->to,depth+1);
		}
		//else printf("结束\n"); 
		temp=temp->next;
	} 
	//For(t,depth) printf("   "); 
	//printf("%d结束\n",i+1);
	node[i].vis=0;	
}







