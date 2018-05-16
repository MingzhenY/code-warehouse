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
	int from,to,v;
	ArcNode *next;
};
struct Node{
	int vis;
	ArcNode *path;
	ArcNode *List;
	Node():List(NULL),path(NULL),vis(0){}
	void init(){
		vis=0;path=NULL;
	}
}node[100];
void Arc(int from,int to,int v){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->v=v;temp->from=from;
	temp->next=node[from].List;
	node[from].List=temp;
}
void DArc(int from,int to,int v){
	Arc(from,to,v);Arc(to,from,v);
}
int N,M;vector<int> TempPath;

int Dis(int i,int end,int dis){
	OUT3(i,end,dis);
	if(i==end){
		return dis;
	}
	TempPath.push_back(i); 
	return Dis(node[i].path->from,end,dis+node[i].path->v);
}
int ANS;vector<int> Path;
void DFS(int i){
	//OUT1(i);
	if(node[i].vis){
		//开始计算这个环的权值。 
		TempPath.clear();
		//int D=Dis(node[i].path->from,i,node[i].path->v);
		int D;
		int k=i;
		For(j,9){
			printf("->%d",k+1);
			k=node[k].path->from;
		} 
		cout<<endl;
		if(!~ANS||D <ANS){
			ANS=D,Path=TempPath;
		}
		return;
	}
	node[i].vis=1;
	ArcNode *temp=node[i].List;
	while(temp){
		if(!node[temp->to].vis||node[temp->to].vis&&node[i].path->from!=temp->to){
			node[temp->to].path=temp;
			DFS(temp->to);
		}
		temp=temp->next;
	} 
	node[i].vis=0;
}
int main(void)
{freopen("1004.txt","r",stdin); 
	while(cin>>N&&(~N)){
		//预处理 
		cin>>M;
		For(i,N) node[i].init();
		For(i,M) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			DArc(a-1,b-1,c);
		}
		//显示 
		/*
		For(i,N){
			printf("%d:",i+1);
			ArcNode *temp=node[i].List;
			while(temp){
				printf("->%d",temp->to+1);
				temp=temp->next;
			}
			cout<<endl;
		}
		*/
		
		//搜索 
		For(i,N) node[i].init();
		ANS=-1;
		For(i,N){
			if(!node[i].vis) DFS(i);
		} 
		//输出
		OUT1(ANS);
		For(i,Path.size()){
			printf("%d->",Path[i]);
		} 
		cout<<endl;
		//释放
		For(i,N){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp; 
			}
		} 
	}
return 0;
}








