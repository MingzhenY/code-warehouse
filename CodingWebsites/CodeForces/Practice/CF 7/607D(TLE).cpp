#include <iostream>
#include <cstdio>
#include <cmath>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
#define maxn 200007
#define M 1000000007
using namespace std;
struct Node{
	LL P,N,Sum,OldS,NewS;
	Node(){}
	Node(LL P,LL N,LL Sum):P(P),N(N),Sum(Sum){OldS=0;NewS=N*Sum%M;}
	void Update(Node &son){
		Sum+=son.NewS-son.OldS;
		son.OldS=son.NewS;
		NewS=N*Sum%M; 
	}
}V[maxn];
int v,q,p,IP,op,u;
int main(void)
{
	freopen("607D.txt","r",stdin); 
	while(~scanf("%d%d",&v,&q)){
		V[IP=1]=Node(1,1,v);
		V[1].OldS=V[1].NewS;
		for(int i=1;i<=q;++i){
			scanf("%d",&op);
			if(op==1){
				scanf("%d%d",&p,&v);
				V[++IP]=Node(p,1,v);
				++V[p].N;
				int temp=IP,Ptemp=V[temp].P;
				while(temp!=1){
					V[Ptemp].Update(V[temp]);
					Ptemp=V[temp=V[temp].P].P;
				}
				V[temp].OldS=V[temp].NewS;
			}
			else{
				scanf("%d",&u);
				printf("%d\n",int(V[u].OldS));
			}
		}
	}
return 0;
}

