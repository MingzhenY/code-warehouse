#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue> 
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
	ArcNode *next;
};
struct Node{
	ArcNode *List;
	Node():List(NULL){}
}node[7500];
void DArc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;
	temp->next=node[to].List;
	node[to].List=temp;
}
int N;
int d[7500];
int a[7500];
int main(void)
{freopen("1069.txt","r",stdin); 

	int t;memset(d,0,sizeof(d));int N=0;
	while(cin>>t){
		a[N++]=t-1;d[t-1]++;
	}
	For(i,N+1) d[i]++;
	priority_queue<int, vector<int>, greater<int> > Q;
	For(i,N+1){
		if(d[i]<2) Q.push(i); 
	}
	For(i,N){
		int t=Q.top();Q.pop();
		DArc(a[i],t);d[a[i]]--;
		if(d[a[i]]==1) Q.push(a[i]); 
	}
	
	For(i,N+1){
		ArcNode *NewList=NULL;
		while(node[i].List){
			ArcNode *temp=node[i].List;
			node[i].List=node[i].List->next;
			temp->next=NewList;
			NewList=temp;
		}
		node[i].List=NewList;
	}
	For(i,N+1){
		ArcNode *temp=node[i].List;
		printf("%d:",i+1);
		while(temp){
			printf(" %d",temp->to+1);
			temp=temp->next;
		}
		cout<<endl;
	}
return 0;
}








