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
#define maxn 501
using namespace std;

struct ArcNode{
	int to;
	ArcNode *next;
};
struct Node{
	ArcNode *List;
	bool vis;
	void init(){
		List=NULL;
		vis=false;
	}
}node[maxn];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
bool arc[maxn][maxn];
bool has[maxn];
int n,m;
int NofEdge,NofU; 
void DFS(int i){
	ArcNode *temp=node[i].List;
	node[i].vis=true;
	while(temp){
		if(!node[temp->to].vis) DFS(temp->to);
		temp=temp->next;
	}
}
int main(void)
{freopen("1124.txt","r",stdin); 
	while(~scanf("%d%d",&m,&n)){
		memset(arc,0,sizeof(arc));
		memset(has,0,sizeof(has));
		for(int i=1;i<=m;++i) node[i].init();
		NofEdge=NofU=0;
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				int to;scanf("%d",&to);
				if(i!=to){
					++NofEdge;
					if(!arc[i][to]){
						arc[i][to]=true;
						Arc(i,to);
						if(!has[i])  has[i]=1;
						if(!has[to]) has[to]=1;
					}
				}
			}
			if(!has[i]) node[i].vis=1;
		}
		for(int i=1;i<=m;++i){
			if(!node[i].vis){
				NofU++;
				DFS(i);
			}
		}
		//OUT2(NofEdge,NofU);
		int ANS=NofU+NofEdge-(NofEdge>0);
		cout<<ANS<<endl;
		
		for(int i=1;i<=m;++i){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		}
	}
return 0;
}








