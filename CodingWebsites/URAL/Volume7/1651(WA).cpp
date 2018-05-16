#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100001
using namespace std;

int n;
int chain[maxn];

//图
struct ArcNode{
	int to,ord;
	ArcNode *next;
}; 
struct Node{
	ArcNode *List;
	int ord,path,dis;//编号，路径，最短路 
}node[10001];
void Show(int k){
	printf("\t节点%d=> dis:%d   ord=%d   path=%d\n",k,node[k].dis,node[k].ord,node[k].path);
}
void Rev(int k){
	ArcNode *nList=NULL;
	while(node[k].List){
		ArcNode *temp=node[k].List;
		node[k].List=node[k].List->next;
		temp->next=nList;
		nList=temp;
	}
	node[k].List=nList;
}
void Arc(int from,int to,int ord){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->ord=ord; 
	temp->next=node[from].List;
	node[from].List=temp;
}
char Inq[10001];
queue<int> Q; 
void DFS(int t){
	ArcNode *temp=node[t].List;
	printf("当前节点:%d\n",t);
	while(temp){
		if(temp->ord>node[t].ord){
			if(!~node[temp->to].dis||node[temp->to].dis>node[t].dis+1||node[temp->to].dis==node[t].dis+1&&temp->ord <node[temp->to].ord){
				node[temp->to].dis=node[t].dis+1;
				node[temp->to].ord=temp->ord;
				node[temp->to].path=t;
				Show(temp->to);
				if(!Inq[temp->to]) Q.push(temp->to),Inq[temp->to]=1;
			}
		}
		temp=temp->next;
	}
}
int main(void)
{freopen("1651.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i) node[i].List=NULL,node[i].dis=-1;//初始化 
		for(int i=1;i<=n;++i){scanf("%d",&chain[i]);}//读取数据 
		for(int i=1;i<n;++i) Arc(chain[i],chain[i+1],i),node[i+1].path=i;//建边
		for(int i=1;i<=n;++i) Rev(i);
		//加入起点 
		node[chain[1]].ord=0;node[chain[1]].dis=0; 
		Q.push(chain[1]);Inq[chain[1]]=1;
		//SPFA
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();Inq[cnt]=0;
			DFS(cnt);
		}
		
		int S=chain[1],T=chain[n];int I=0;
		while(T!=S){
			chain[++I]=T;
			T=node[T].path;
		}
		chain[++I]=S;
		for(int i=I;i>0;--i) {
			printf("%d",chain[i]);
			if(i==1) printf("\n");
			else printf(" ");
		}
		for(int i=1;i<=n;++i){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		} 
	}
return 0;
}








