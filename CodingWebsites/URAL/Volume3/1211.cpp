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
	int In;
	ArcNode*List;
}node[25000];
void Arc(int from,int to){
	ArcNode*temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
	node[to].In++;
}
int N;
int main(void)
{freopen("1211.txt","r",stdin); 
	int T;cin>>T;
	FOR(TT,T){
		cin>>N;int Confess=0;queue<int> Q;
		For(i,N) node[i].In=0,node[i].List=NULL;
		For(i,N){
			int a;scanf("%d",&a);
			if(a) Arc(i,a-1);
			else Confess++;
		}
		For(i,N) if(node[i].In==0) Q.push(i);
		int T=1;//³ÉÁ¢ 
		if(Confess!=1) T=0;
		if(T){
			int Del=0;
			while(!Q.empty()){
				int cnt=Q.front();Q.pop();Del++;
				ArcNode*temp=node[cnt].List;
				while(temp){
					node[temp->to].In--;
					if(!node[temp->to].In) Q.push(temp->to);
					temp=temp->next;
				}
			}
			if(Del<N) T=0;
		}
		
		if(T) printf("YES\n");
		else printf("NO\n");
	}
	
	
	
	
return 0;
}








