#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
	bool vis;
	Node():vis(0){}
	ArcNode *List;
}node[1007];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to){Arc(from,to);Arc(to,from);}
int n,k;vector<int> A;
bool DFS(int cnt){
	ArcNode *temp=node[cnt].List;
	int All=(cnt==k)-1,Win=0;
	while(temp){
		All++;
		if(!node[temp->to].vis){
			node[cnt].vis=1;
			int Q=DFS(temp->to);
			node[cnt].vis=0;
			Win+=Q;
			if(cnt==k&&!Q) A.push_back(temp->to);
		}
		temp=temp->next;
	}
	return All>Win;
}
int main(void)
{freopen("1045.txt","r",stdin); 
	cin>>n>>k;
	for(int i=1;i<n;++i) {int a,b;scanf("%d%d",&a,&b);DArc(a,b);}
	if(DFS(k)){
		int Min=0x7fffffff;
		for(int i=0;i<A.size();++i) if(A[i]<Min) Min=A[i];
		printf("First player wins flying to airport %d\n",Min);
	}
	else{
		printf("First player loses\n");
	}
return 0;
}








