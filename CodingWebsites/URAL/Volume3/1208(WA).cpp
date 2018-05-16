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
	ArcNode *next;
};
struct Node{
	string name[3];
	ArcNode *list;
	int used;
	void init(){
		list=NULL;
	}
	void clear(){
		while(list){
			ArcNode *temp=list;
			list=list->next;
			delete temp;
		}
	}
}node[18];
void Arc(int from,int to){
	ArcNode*temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].list;
	node[from].list=temp;
}
void DArc(int from,int to){
	Arc(from,to);
	Arc(to,from);
}
int N; 
queue<int> Q;
void BFS(int i){
	ArcNode *temp=node[i].list;
	while(temp){
		if(!~node[temp->to].used){
			node[temp->to].used=!node[i].used;
			Q.push(temp->to);
		}
		temp=temp->next;
	} 
}
int main(void)
{freopen("1208.txt","r",stdin); 
	while(cin>>N){
		//读取 
		For(i,N){
			node[i].init();
			For(j,3) cin>>node[i].name[j];
		}
		//建图 
		For(i,N){
			for(int j=i+1;j<N;j++){
				int T=0;
				For(k,3){
					For(s,3){
						if(node[i].name[k]==node[j].name[s]){
							DArc(i,j);T=1;break;
						}
					}
					if(T) break;
				}
			}
		}/*
		For(i,N){
			printf("节点%d:",i+1);
			ArcNode *temp=node[i].list;
			while(temp){
				printf("->%d",temp->to+1);
				temp=temp->next;
			}
			cout<<endl;
		}*/
		//计算 
		int ANS=0;
		For(start,N){//以i为起点搜索 
			int ANSN=0;
			For(i,N) node[i].used=-1;
			
		}
		cout<<ANS<<endl;
		//释放 
		For(i,N) node[i].clear();
	}
	
	
	
	
return 0;
}








