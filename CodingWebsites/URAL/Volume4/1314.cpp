#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
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
	ArcNode*next;
};
struct Node{
	int D[2];
	bool vis;
	ArcNode *List;
}node[32768];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to){
	Arc(from,to);Arc(to,from);
}
int N,M;
queue<int>Q;
void bfs(int k,int t){
	ArcNode*temp=node[k].List;
	while(temp){
		if(t&&node[temp->to].vis) {
			temp=temp->next;
			continue;
		} 
		if(!~node[temp->to].D[t]||node[temp->to].D[t]>node[k].D[t]+1){
			node[temp->to].D[t]=node[k].D[t]+1;
			Q.push(temp->to);
		}	
		temp=temp->next;
	}
}
void caculate(int v,int t){
	while(!Q.empty()) Q.pop();
	node[v].D[t]=0;
	Q.push(v);
	while(!Q.empty()){
		int cnt=Q.front();Q.pop();
		bfs(cnt,t);
	}
}
int main(void)
{freopen("1314.txt","r",stdin); 
	while(cin>>N){
		FOR(i,32767) node[i].D[0]=-1,node[i].D[1]=-1,node[i].List=NULL,node[i].vis=0;
		For(i,N){
			int n,last;scanf("%d%d",&n,&last);
			For(j,n-1){
				int a;scanf("%d",&a);
				DArc(a,last);
				last=a;
			}
		}
		scanf("%d",&M);int A,B;//Æðµã£¬ÖÕµã 
		
		For(i,M){
			if(i){
				scanf("%d",&B);
				node[B].vis=1;
			}
			else{
				scanf("%d",&A);
				node[A].vis=1;
			}
		}
		if(M==1) B=A;
		caculate(A,0);
		caculate(B,1);
		for(int i=1;i<=32767;i++){
			if(i==B){
				printf("%d\n",i);continue;
			}
			if(node[i].List&&!node[i].vis){
				if(~node[i].D[0]&&~node[i].D[1]){
					if(node[i].D[0]+1==node[i].D[1]+M){
						printf("%d\n",i);
					}	
				}
			}
		}
	}
return 0;
}








