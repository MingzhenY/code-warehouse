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
	bool up;
	ArcNode *next;
};
struct Node{
	int disUp;
	int disDown;
	ArcNode *List;
	void init(){
		List=NULL;disUp=disDown=inf;
	}
	void clear(){
		while(List){
			ArcNode *temp=List;
			List=List->next;
			delete temp;
		} 
	}
}node[10000];
void Arc(int from,int to,int t){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->up=t;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to){
	Arc(from,to,1);
	Arc(to,from,0);
}
int N,M,start,end;
queue<int> Q;
void BFS(int i){
	ArcNode *temp=node[i].List;
	while(temp){
		int D;
		if(temp->up){
			D=min(node[i].disUp,node[i].disDown+1);
			if(D <node[temp->to].disUp) {
				node[temp->to].disUp=D;
				Q.push(temp->to);
			}
		}
		else{
			D=min(node[i].disUp+1,node[i].disDown);
			if(D <node[temp->to].disDown){
				node[temp->to].disDown=D ;
				Q.push(temp->to);
			}
		}
		temp=temp->next;
	}
}
int main(void)
{freopen("1930.txt","r",stdin); 
	while(cin>>N>>M){
		//预处理 
		For(i,N) node[i].init();
		For(i,M){
			int a,b;
			scanf("%d%d",&a,&b);
			DArc(a-1,b-1);
		}
		cin>>start>>end;start--,end--;
		//计算 
		node[start].disDown=node[start].disUp=0;
		Q.push(start);
		while(!Q.empty()){
			int t=Q.front();Q.pop();
			BFS(t);
		}
		
		cout<<min(node[end].disUp,node[end].disDown)<<endl;
		//释放 
		For(i,N) node[i].clear();
	}
return 0;
}








