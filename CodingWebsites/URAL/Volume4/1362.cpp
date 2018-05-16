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
	ArcNode*next;
};
struct Node{
	int Dis;
	int n;
	bool vis;
	ArcNode*List;
}node[100001];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	node[from].n++;
}
void DArc(int from,int to){
	Arc(from,to);Arc(to,from);
}
int dfs(int rt){
	if(node[rt].n==0) return 0;
	int *ans=new int[node[rt].n];
	ArcNode*temp=node[rt].List;
	int n=0;node[rt].vis=1;
	while(temp){
		if(!node[temp->to].vis){
			ans[n++]=dfs(temp->to);
		}
		temp=temp->next;
	}
	sort(ans,ans+n);int ANS=0; 
	for(int i=0;i<n;i++){
		ans[i]+=n-i;
		if(ans[i]>ANS) ANS=ans[i];
	}
	delete []ans;
	return ANS;
}
int N;
int main(void)
{freopen("1362.txt","r",stdin); 
	while(cin>>N){
		FOR(i,N) node[i].n=-1,node[i].vis=0,node[i].List=NULL;
		FOR(i,N){
			int a;
			while(~scanf("%d",&a)&&a){
				DArc(i,a);
			}
		}
		int rt;scanf("%d",&rt);node[rt].n++;
		int ANS=dfs(rt);
		printf("%d\n",ANS);
	}
return 0;
}








