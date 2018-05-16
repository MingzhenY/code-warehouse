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
#define SQRT(A,B) sqrt((A)*(A)+(B)*(B))
using namespace std;
struct ArcNode{
	int to;
	double dis;
	ArcNode *next; 
};
struct Node{
	double x,y;
	double dis;
	int path;
	ArcNode *list;
}node[202];
void Arc(int from,int to,double dis){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->dis=dis;
	temp->next=node[from].list;
	node[from].list=temp;
}
void DArc(int from,int to,double dis){
	Arc(from,to,dis);Arc(to,from,dis);
}
queue<int> Q;
void BFS(int i){
	ArcNode *temp=node[i].list;
	while(temp){
		if(node[temp->to].dis<0||node[i].dis+temp->dis<node[temp->to].dis){
			node[temp->to].dis=node[i].dis+temp->dis;
			node[temp->to].path=i;
			Q.push(temp->to);
		}
		temp=temp->next;
	}
}
void F(int i){
	if(node[i].path) {
		F(node[i].path);
		printf(" %d",node[i].path);
	}
}
int main(void)
{freopen("1205.txt","r",stdin); 
	double v1,v2;int N;
	while(cin>>v1>>v2){
		cin>>N;
		FOR(i,N){
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}
		int a,b;
		FOR(i,N){
			for(int j=i+1;j<N;j++){
				double dis=SQRT(node[i].x-node[j].x,node[i].y-node[j].y)/v1;
				DArc(i,j,dis);
			}
		}
		while(scanf("%d%d",&a,&b)&&(a||b)){
			double dis=SQRT(node[a].x-node[b].x,node[a].y-node[b].y)/v2;
			DArc(a,b,dis);
		}
		scanf("%lf%lf",&node[0].x,&node[0].y);
		scanf("%lf%lf",&node[N+1].x,&node[N+1].y);
		FOR(i,N){
			double dis=SQRT(node[0].x-node[i].x,node[0].y-node[i].y)/v1;
			Arc(0,i,dis);
			dis=SQRT(node[N+1].x-node[i].x,node[N+1].y-node[i].y)/v1;
			Arc(i,N+1,dis);
		}
		Arc(0,N+1,SQRT(node[0].x-node[N+1].x,node[0].y-node[N+1].y)/v1);
		For(i,N+2) node[i].dis=-1,node[i].path=i;
		node[0].dis=0;
		Q.push(0);
		while(!Q.empty()){
			int Cnt=Q.front();Q.pop();
			BFS(Cnt);
		}
		printf("%.7f\n",node[N+1].dis);
		int t=node[N+1].path;int ALL=0;
		while(t){
			//if(t!=node[N+1].path) printf(" ");
			//printf("%d",t);
			ALL++;
			t=node[t].path;
		}
		cout<<ALL;
		F(N+1);
		cout<<endl;
	}
	
	
	
	
return 0;
}








