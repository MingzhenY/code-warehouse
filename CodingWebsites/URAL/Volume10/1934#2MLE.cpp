#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct A{
	int d;
	float p;
	A():d(1000000){}
	A(float p):d(1),p(p){}
	A operator+(const A&B)const{
		A C;
		C.d=d+B.d;
		C.p=p+B.p-p*B.p;
		return C;
	}
	bool operator<(const A&B)const{
		return d <B.d||d==B.d&&p<B.p;
	}
};
struct ArcNode{
	int to;float p;
	ArcNode*next;
}Arcy[200000]; int ArcN;
A dis[100000];
int path[100000];
ArcNode *List[100000];

void Arc(int from,int to,int p){
	ArcNode *temp;
	temp=&Arcy[ArcN++];
	temp->to=to;temp->p=p/100.0;
	temp->next=List[from];
	List[from]=temp;
	temp=&Arcy[ArcN++];
	temp->to=from;temp->p=p/100.0;
	temp->next=List[to];
	List[to]=temp;
}
queue<int> Q;
void BFS(int i){
	while(List[i]){
		ArcNode *temp=List[i];
		if(dis[temp->to].d==1000000) Q.push(temp->to);
		if(dis[i]+A(temp->p)<dis[temp->to]){
			dis[temp->to]=dis[i]+A(temp->p);
			path[temp->to]=i;
			//if(!Inq[temp->to]) Q.push(temp->to),Inq[temp->to]=1;
		}
		List[i]=List[i]->next;
		//delete temp;
	}
}
int N,M,s,t; 
void F(int i){
	if(i!=path[i]){
		F(path[i]);
		printf(" %d",i+1);
	}
}
int main(void)
{freopen("1934.txt","r",stdin); 
	
	scanf("%d%d%d%d",&N,&M,&s,&t);
		ArcN=0;
		For(i,N) List[i]=NULL;
		For(i,M){
			int a,b,p;
			scanf("%d%d%d",&a,&b,&p);
			Arc(a-1,b-1,p); 
		}
		s--,t--;
		Q.push(s);
		dis[s].d=0;dis[s].p=0.0;
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();
			BFS(cnt);
		}
		printf("%d %f\n",dis[t].d+1,dis[t].p);
		printf("%d",s+1);
		F(t);
		printf("\n");
		
	
return 0;
}








