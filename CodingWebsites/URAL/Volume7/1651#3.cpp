#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct ArcNode{
	int to,ord;
	ArcNode *next;
};
struct SideNode{
	int dis,ord,path;
	SideNode *next;
}; 
struct Node{
	SideNode *Side;
	ArcNode *List;
}node[10001];

void AddSide(int k,int dis,int ord,int path){
	SideNode *temp=new SideNode;
	temp->dis=dis;temp->ord=ord;temp->path=path;
	temp->next=node[k].Side;
	node[k].Side=temp;
}
void AddArc(int k,int to,int ord){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->ord=ord;
	temp->next=node[k].List;
	node[k].List=temp; 
}
int n;
int chain[100001];
queue <int> Q;
char Inq[10001];
void BFS(int cnt){
	SideNode *tempCnt=node[cnt].Side;
	while(tempCnt){//对于本点的每个状态 
		ArcNode *tempArc=node[cnt].List;
		while(tempArc){//对于每条出边 
			if(tempArc->ord > tempCnt->ord){//若符合条件 
				SideNode *List=NULL;int T=1;
				int newOrd=tempArc->ord;
				int newdis=tempCnt->dis+1;
				while(node[tempArc->to].Side){//更新目的地的每一个状态 
					SideNode *temp=node[tempArc->to].Side;
					node[tempArc->to].List=node[tempArc->to].List->next;
					if(T){
						if(newdis <= temp->dis&&newOrd <= temp->ord){
							delete temp;temp=NULL;
						}
						else if(newdis>=temp->dis&&newOrd>=temp->ord){
							T=0;
						}
					}
					if(temp){
						temp->next=List;
						List=temp;
					}
				}
				node[tempArc->to].Side=List;
				if(T){
					AddSide(tempArc->to,newdis,newOrd,cnt);
				}
			}
			tempArc=tempArc->next;
		}
		tempCnt=tempCnt->next;
	}
}
int main(void)
{freopen("1651.txt","r",stdin); 
	while(cin>>n){
		for(int i=1;i<=n;++i) scanf("%d",&chain[i]),Inq[i]=0;
		for(int i=1;i<n;++i) AddArc(chain[i],chain[i+1],i); 
		
		
		AddSide(chain[1],0,0,0);
		Q.push(chain[1]);Inq[chain[1]]=1;
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();Inq[cnt]=0;
			BFS(cnt);
		}	
		SideNode *MinSide=NULL,int Min=inf;
		SideNode *temp=node[chain[n]].Side;
		while(temp){
			if(temp->dis<Min){
				Min=temp->dis;
				MinSide=temp;
			}
			temp=temp->next;
		}
		if(MinSide){
			int T=
		}
	}
	
	
	
return 0;
}





























