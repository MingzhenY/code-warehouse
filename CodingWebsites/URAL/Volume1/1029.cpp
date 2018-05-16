#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
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
	int to;int v;
	ArcNode *next;
};
struct Node{
	bool Inq;//是否在队列中
	long long dis;//最短路径长度 
	int path;//上个节点 
	void clear(){
		Inq=0;dis=-1;path=-1;
	}
	ArcNode *List;//出边表 
}node[50002];
void Arc(int from,int to,int value){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->v=value;
	temp->next=node[from].List;
	node[from].List=temp; 
}

int p[100][500];
int dx[3]={0,1,0};
int dy[3]={-1,0,1};
int M,N;//M层，N房间 

int F(int i);//输出结果 
int main(void)
{freopen("1029.txt","r",stdin); 
	while(cin>>M>>N){
		//读取 
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&p[i][j]);
			}
		}
		//建图 
		for(int i=0;i<=M*N+1;i++) node[i].List=NULL;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				for(int k=0;k<3;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if(nx>=0&&nx<M&&ny>=0&&ny<N){
						Arc(i*N+j+1,nx*N+ny+1,p[nx][ny]);
					}
				}
			}
		}
		//源点连接第一层,第M层连接汇点
		for(int i=0;i<N;i++){
			Arc(0,i+1,p[0][i]);
			Arc((M-1)*N+i+1,N*M+1,0);
		}
		//测试输出（通过） 
		/*
		for(int i=0;i<=N*M+1;i++){
			printf("%d:",i);
			ArcNode *temp=node[i].List;
			while(temp){
				printf("->%d(%d,%d)",temp->to,(temp->to-1)/N,(temp->to-1)%N);
				temp=temp->next;
			}
			cout<<endl;
		}
		*/
		
		//SPFA初始化
		for(int i=0;i<=M*N+1;i++) node[i].clear();
		queue<int> Q;
		Q.push(0);node[0].Inq=1;node[0].dis=0;
		//开始SPFA 
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();node[cnt].Inq=0;
			ArcNode *temp=node[cnt].List;
			while(temp){
				Node &T=node[temp->to];int Flag=0;
				if(~T.dis){
					if(T.dis>node[cnt].dis+temp->v) Flag=1;
				}else Flag=1;
				if(Flag){
					T.dis=node[cnt].dis+temp->v;
					T.path=cnt;
					if(!node[temp->to].Inq) {
						Q.push(temp->to);
						node[temp->to].Inq=1;
					}
				}
				temp=temp->next;
			}
		}
		F(node[N*M+1].path);
	}
	
return 0;
}
int F(int i){
	if(node[i].path) F(node[i].path);
	printf("%d",(i-1)%N+1);
	if(i==node[N*M+1].path) printf("\n");
	else printf(" ");
} 







