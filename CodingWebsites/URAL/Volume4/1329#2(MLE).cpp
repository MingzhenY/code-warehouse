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
int N,L;
struct ArcNode{
	int to;
	ArcNode*next;
};
struct Question{
	int a,b;
	bool Ta,Tb;//记录是否包含另一个。
}Q[40001];
struct Node{
	ArcNode*List;
	ArcNode*QList;
}node[40001];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
void Arc2(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].QList;
	node[from].QList=temp;
}
vector<bool> DFS(int rt,vector<int>V){
	int n=V.size();vector<bool> ANS;
	//加入自己的问题
	ArcNode *temp=node[rt].QList;
	while(temp){
		//Q[temp->to]
		if(rt==Q[temp->to].a) V.push_back(Q[temp->to].b);
		else V.push_back(Q[temp->to].a);
		temp=temp->next;
	}
	//询问
	int N=V.size();
	For(i,N) ANS.push_back(0);
	temp=node[rt].List;
	while(temp){
		vector<bool> tANS=DFS(temp->to,V);
		For(i,N) ANS[i]=ANS[i]||tANS[i];
		temp=temp->next; 
	}
	//回答自己的问题
	temp=node[rt].QList;
	for(int i=n;i<N;i++){
		if(V[i]==Q[temp->to].a)  Q[temp->to].Tb=ANS[i];
		else  Q[temp->to].Ta=ANS[i];
		temp=temp->next;
	}
	//回答上面的问题
	vector<bool> TANS;
	For(i,n){
		TANS.push_back(ANS[i]||rt==V[i]);
	}
	return TANS;
}
int main(void)
{freopen("1329.txt","r",stdin); 
	while(cin>>N){
		int a,b;
		FOR(i,40000) node[i].List=NULL,node[i].QList=NULL;
		int rt=-1;
		For(i,N){
			scanf("%d%d",&a,&b);
			if(!~b) rt=a;
			else Arc(b,a); 	
		}
		
		cin>>L;
		For(i,L){
			scanf("%d%d",&Q[i].a,&Q[i].b);
			Arc2(Q[i].a,i);
			Arc2(Q[i].b,i);
		}
		vector<int> temp;
		DFS(rt,temp);
		For(i,L){
			printf("%d\n",(int)Q[i].Ta+(int)Q[i].Tb*2);
		}
	}
return 0;
}








