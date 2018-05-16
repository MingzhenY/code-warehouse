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
	int vis;
	int path;
	ArcNode *List;
	void init(){
		vis=0;path=-1;List=NULL;
	}
}node[200];
void Darc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;
	temp->next=node[to].List;
	node[to].List=temp;
}
int N,M;

int ans[200][200];int AN;
unsigned long long Mark[200][4];
int ansn[200];
void dfs(int i,int depth); 
void SetMark(int i,int t){
	Mark[i][t/64]^=(1ll<<(t%64));
}
int main(void)
{/*
int tempa;
OUT3(Mark[0][0],Mark[0][1],Mark[0][2]);
while(cin>>tempa) {
	SetMark(0,tempa);
	OUT3(Mark[0][0],Mark[0][1],Mark[0][2]);
}
return 0;*/
freopen("1077.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,N) node[i].init();
		//建图 
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
		memset(Mark,0,sizeof(Mark));
		dfs(0,1);
		printf("%d\n",AN);
		For(i,AN){
			
			printf("%d",ansn[i]);
			
			For(j,ansn[i]) {
				printf(" %d",ans[i][j]+1);
			}
			cout<<endl;OUT3(Mark[i][0],Mark[i][1],Mark[i][2]);
		} 
	}
	
return 0;
}
void dfs(int i,int depth){
	if(node[i].vis){
		if(!i&&(depth>3)){
			//printf("找到长度为%d的路径：",depth-1) ; 
			int T=1;int k=i;ansn[AN]=0;
			Mark[AN][0]=Mark[AN][1]=Mark[AN][2]=Mark[AN][3]=0;
			For(t,depth-1){
				//printf("->%d",k+1);
				ans[AN][ansn[AN]++]=k;
				SetMark(AN,k);
				k=node[k].path;
			}
			For(j,AN){
				int TT=0;
				For(tt,4) if(Mark[AN][tt]!=Mark[j][tt]) TT=1;
				if(!TT) T=0; 
			}
			if(T){//如果符合条件 
				AN++;
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
			dfs(temp->to,depth+1);
		}
		//else printf("结束\n"); 
		
		temp=temp->next;
	} 
	//For(t,depth) printf("   "); 
	//printf("%d结束\n",i+1);
	node[i].vis=0;	
}







