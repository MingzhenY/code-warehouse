#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
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
	int time,limit;//时间和上限 
	ArcNode*next; 
};
struct Node{
	int D;//最短时间
	ArcNode *List;
	Node():List(NULL){} 
}node[501];
void Arc(int from,int to,int time,int limit){
	ArcNode*temp=new ArcNode;
	temp->to=to;temp->time=time;temp->limit=limit;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to,int time,int limit){
	Arc(from,to,time,limit);Arc(to,from,time,limit);
}
bool inq[501];
queue<int>Q;int n,m;
void dfs(int k,int load){
	ArcNode*temp=node[k].List;
	while(temp){
		if(load <=temp->limit){
			if(node[temp->to].D> node[k].D+temp->time){
				node[temp->to].D=node[k].D+temp->time;
				if(!inq[temp->to]) Q.push(temp->to);
			}
		}
		temp=temp->next;
	}
}
bool SPFA(int load){
	int weight=load*100+3000000;
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n;++i) node[i].D=inf,inq[i]=0;
	node[1].D=0;Q.push(1);
	while(!Q.empty()){
		int cnt=Q.front();Q.pop();inq[cnt]=0;
		dfs(cnt,weight);
	}
	return node[n].D <=1440; 
}

int main(void)
{freopen("1379.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<m;i++){
			int a,b,t,v;
			scanf("%d%d%d%d",&a,&b,&t,&v);
			DArc(a,b,t,v);
		}
		int L=0,R=10000000,M,D;
		int ANS=0;
		begin:
			if(L>R) goto end;
			M=(L+R)>>1;
			D=SPFA(M);
			if(D){
				ANS=M;
				L=M+1; 
				goto begin;
			}
			else{
				R=M-1;
				goto begin;
			}
		end:
		printf("%d\n",ANS);
	}
return 0;
}








