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
	ArcNode *next; 
};
struct Node{
	int on;
	ArcNode *pa;
	ArcNode *child;
}node[1001];
void Arc(int pa,int child){
	ArcNode *temp=new ArcNode;
	temp->to=child;
	temp->next=node[pa].child;
	node[pa].child=temp;
	temp=new ArcNode; 
	temp->to=pa;
	temp->next=node[child].pa;
	node[child].pa=temp; 
}
int N;
void DFS_UP(int i){
	node[i].on=0;
	ArcNode *temp=node[i].pa;
	while(temp){
		DFS_UP(temp->to);
		temp=temp->next;
	}
}
void DFS_DOWN(int i){
	//OUT1(i);
	node[i].on=0;
	ArcNode *temp=node[i].child;
	while(temp){
		DFS_DOWN(temp->to);
		temp=temp->next;
	}
}
int main(void)
{freopen("1242.txt","r",stdin); 
	
	cin>>N;
	FOR(i,N) node[i].pa=NULL,node[i].child=NULL;
	string a;
	while(cin>>a){
		if(a[0]=='B') break;
		int child=atoi(a.c_str()),pa;
		
		scanf("%d",&pa);
		//OUT2(child,pa);
		Arc(pa,child);
	}
	FOR(i,N) node[i].on=1;
	int vic;
	while(cin>>vic){
		//OUT1(vic);
		DFS_UP(vic);
		DFS_DOWN(vic);
	}
	int T=0;
	FOR(i,N){
		if(node[i].on) {
			if(T) printf(" ");
			printf("%d",i),T++;
		}
	}
	if(!T) cout<<0;
	cout<<endl;
return 0;
}








