#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 400007
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct Node{
	int L,R,V;//[L,R),Value
	Node(){}
	Node(int L,int R,int V):L(L),R(R),V(V){}
}K[maxn<<2];
int L[maxn<<2],R[maxn<<2],S[maxn<<2],IP;
void zig(int &rt){
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	rt=t;
}
void zag(int &rt){
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	rt=t;
}
void level(int &rt){
	if(S[L[L[rt]]]>S[R[rt]]){zag(rt);level(R[rt]);level(rt);return;}
	if(S[R[R[rt]]]>S[L[rt]]){zig(rt);level(L[rt]);level(rt);return;}
	if(S[R[L[rt]]]>S[R[rt]]){zig(L[rt]);zag(rt);level(L[rt]);level(R[rt]);return;}
	if(S[L[R[rt]]]>S[L[rt]]){zag(R[rt]);zig(rt);level(L[rt]);level(R[rt]);return;}
}
void Insert(int &rt,Node X){
	if(!rt){rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=X;return;}
	if(X.L <= K[rt].L) Insert(L[rt],X);
	else Insert(R[rt],X);
	++S[rt];
	level(rt);
}
void Update(int &rt,int Lx,int Rx,int C){//[Lx,Rx)   
	if(!rt) return;//[ K[rt].L,K[rt].R ) -- K[rt].V
	if(Lx >= K[rt].R) {Update(R[rt],Lx,Rx,C);return;}
	if(Rx <= K[rt].L) {Update(L[rt],Lx,Rx,C);return;}
	if(Lx <= K[rt].L){
		Update(L[rt],Lx,Rx,C);
		if(Rx < K[rt].R){//split into [K[rt].L,Rx)+[Rx,K[rt].R)
			if(C > K[rt].V){
				Insert(R[rt],Node(Rx,K[rt].R,K[rt].V));
				K[rt].R=Rx;K[rt].V=C; 
			}
		}
		else {
			Update(R[rt],Lx,Rx,C);
			if(C > K[rt].V) K[rt].V=C;
		}
	}
	else{
		if(Rx < K[rt].R){//[K[rt].L,Lx) + [Lx,Rx) + [Rx,K[rt].R)
			if(C > K[rt].V){
				Insert(L[rt],Node(K[rt].L,Lx,K[rt].V));
				Insert(R[rt],Node(Rx,K[rt].R,K[rt].V));
				K[rt].L=Lx;K[rt].R=Rx;K[rt].V=C;	
			}
		}
		else{//[K[rt].L,Lx) + [Lx,K[rt].R)
			Update(R[rt],Lx,Rx,C);
			if(C > K[rt].V){
				Insert(L[rt],Node(K[rt].L,Lx,K[rt].V));
				K[rt].L=Lx;K[rt].V=C;	
			}
		}
	}
	level(rt);
}
int GetV(int rt,int x){
	if(x < K[rt].L) return GetV(L[rt],x);
	if(x >=K[rt].R) return GetV(R[rt],x);
	return K[rt].V;
}
void Show(int rt){
	if(S[L[rt]]) Show(L[rt]);
	printf("[%d,%d):%d \n",K[rt].L,K[rt].R,K[rt].V);
	if(S[R[rt]]) Show(R[rt]);
}
void Test(){
	L[0]=R[0]=S[0]=IP=0;
	K[0].L=-1;K[0].R=0x7fffffff;K[0].V=-1;
	int SBT=0;
	Insert(SBT,Node(1,10,2));
	Update(SBT,2,7,3);
	Show(SBT);
	Update(SBT,5,9,4);
	Show(SBT);
	
}
int n,q;
int main(void)
{
	freopen("555C.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		L[0]=R[0]=S[0]=IP=0;
		K[0].L=-1;K[0].R=0x7fffffff;K[0].V=-1;
		int TU=0,TL=0;
		Insert(TU,Node(0,n,0));
		Insert(TL,Node(0,n,0));
		int x,y;char op;int ANS;
		for(int i=0;i<q;++i){
			scanf("%d%d %c",&x,&y,&op);
			if(op=='U'){
				int T=min(GetV(TU,x-1),n+1-x);
				//OUT1(T);
				ANS=y-T;
				Update(TU,x-1,x,y);
				Update(TL,T,y,x);
			}
			else{
				int T=min(GetV(TL,y-1),n+1-y);
				//OUT1(T);
				ANS=x-T;
				Update(TL,y-1,y,x);
				Update(TU,T,x,y);
			}
			printf("%d\n",ANS);
			//printf("TU:\n");Show(TU);
			//printf("TL:\n");Show(TL);
		}
	}
return 0;
}

