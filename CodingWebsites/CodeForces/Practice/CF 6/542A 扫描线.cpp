/*
982 ms	49300 KB
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring> 
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 200007
#define LL long long
using namespace std;
//SBT(Size Balanced Tree)
struct Node{
	int V,ID;
	Node():V(0),ID(0){}
	Node(int V,int ID):V(V),ID(ID){}
	bool operator <(const Node &B)const{return V < B.V || V==B.V && ID < B.ID;}
	bool operator ==(const Node &B)const{return V==B.V&&ID==B.ID;}
}K[maxn<<1];
int L[maxn<<1],R[maxn<<1],S[maxn<<1],IP,TA,TB;
void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;} 
void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void lev(int &x,bool flag){
	if(flag){
		if(S[L[L[x]]]>S[R[x]]) zag(x);
		else if(S[R[L[x]]]>S[R[x]]) {zig(L[x]);zag(x);}
		else return;
	}
	else{
		if(S[R[R[x]]]>S[L[x]]) zig(x);
		else if(S[L[R[x]]]>S[L[x]]){zag(R[x]);zig(x);}
		else return;
	}
	lev(L[x],true);lev(R[x],false);
	lev(x,true);lev(x,false);
}
void Insert(int &rt,Node X){
	if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=X;return;}
	X < K[rt]?Insert(L[rt],X):Insert(R[rt],X);
	++S[rt];lev(rt,X < K[rt]);
}
Node Delete(int &rt,Node X){
	Node Del;--S[rt];
	if(X == K[rt] || X < K[rt] && !L[rt] || K[rt] < X && !R[rt]){
		Del=K[rt];
		if(!L[rt]||!R[rt]) rt=L[rt]+R[rt];
		else K[rt]=Delete(L[rt],X);
	}
	else Del=X < K[rt]?Delete(L[rt],X):Delete(R[rt],X);
	lev(rt,K[rt]<X);
	return Del;
}
int Min(int &rt){return L[rt]?Min(L[rt]):rt;}
int Max(int &rt){return R[rt]?Max(R[rt]):rt;}
//非递归线段树 -- 单点修改，维护区间最大值 
//Segment Tree 
Node ST[maxn<<4]; 
int N;
void Build(int n){
	N=1;while(N < n+2) N <<= 1;
	int I=N <<1;
	Node X=Node(0,0);
	for(int i=0;i<I;++i) ST[i]=X;
}
void Update(int L,Node X){
	for(int s=N+L;s;s>>=1){
		if(ST[s]<X) ST[s]=X;
		else break;
	}
}
Node Query(int L,int R){
	Node ANS;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1&&ANS < ST[s^1]) ANS=ST[s^1];
		if( t&1&&ANS < ST[t^1]) ANS=ST[t^1];
	}
	return ANS;
}
//离散化
int Rank[maxn<<2],Rn;
void SortRank(){
	int I=1;
	sort(Rank+1,Rank+Rn+1);
	for(int i=2;i<=Rn;++i) if(Rank[i]!=Rank[i-1]) Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=Rn;//[L,R] first >=x
	while(L^R){
		int M=(L+R)>>1;
		if(Rank[M]<x) L=M+1;
		else R=M; 
	}
	return L;
}
//Information
struct Window{
	int A,B,C;//[A,B)--C
	Window(){}
	Window(int A,int B,int C):A(A),B(B),C(C){}
}W[maxn];int Wn;
struct Ad{
	int L,R;//[L,R)
	Ad(){}
	Ad(int L,int R):L(L),R(R){}
}A[maxn];int An;
//SweepLine
struct SweepLine{
	int X,ID;
	bool TYPE,IN;//type1=Ad type0=Window 
	SweepLine(){}
	SweepLine(int X,int ID,int TYPE,int IN):X(X),ID(ID),TYPE(TYPE),IN(IN){}
	bool operator <(const SweepLine &B)const{return X < B.X || X==B.X && TYPE < B.TYPE;} 
}Line[maxn<<2];int Ln;
int n,m;
int main(void)
{
	freopen("542A.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		Ln=Rn=An=Wn=0;
		for(int i=1;i<=n;++i){
			int l,r;scanf("%d%d",&l,&r);
			Rank[++Rn]=l;
			Rank[++Rn]=r;
			A[++An]=Ad(l,r);
		}
		for(int i=1;i<=m;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			Rank[++Rn]=a;
			Rank[++Rn]=b;
			W[++Wn]=Window(a,b,c);
		}
		//离散化
		SortRank();
		//扫描线
		for(int i=1;i<=n;++i){
			Line[Ln++]=SweepLine(GetRank(A[i].L),i,1,1);
			Line[Ln++]=SweepLine(GetRank(A[i].R),i,1,0);
		}
		for(int i=1;i<=m;++i){
			Line[Ln++]=SweepLine(GetRank(W[i].A),i,0,1);
			Line[Ln++]=SweepLine(GetRank(W[i].B),i,0,0);
		}
		sort(Line,Line+Ln);
		L[0]=R[0]=S[0]=IP=TA=TB=0;//SBT初始化 
		Build(Rn);//线段树初始化 
		LL ANS=0;int I=0,AID,WID;
		for(int i=1;i<=Rn;++i){
			while(I < Ln && Line[I].X == i){
			 	if(Line[I].TYPE){//更新 
			 		if(Line[I].IN){//L操作 
			 			Insert(TB,Node(A[Line[I].ID].L,Line[I].ID));
			 			Insert(TA,Node(A[Line[I].ID].R,Line[I].ID));
			 		}
			 		else{//R操作 
			 			Delete(TB,Node(A[Line[I].ID].L,Line[I].ID));
			 			Delete(TA,Node(A[Line[I].ID].R,Line[I].ID));
			 			Update(GetRank(A[Line[I].ID].L),Node(A[Line[I].ID].R-A[Line[I].ID].L,Line[I].ID));
			 		}
			 	}
			 	else{//计算 
			 		if(Line[I].IN){//A操作 
			 			int rt=Max(TA);
			 			if(rt){
				 			LL D=((LL) W[Line[I].ID].C)*(min(W[Line[I].ID].B,K[rt].V)-W[Line[I].ID].A);
				 			if(D > ANS){
				 				ANS=D;
				 				WID=Line[I].ID;
				 				AID=K[rt].ID;
				 			}	
			 			}
			 			
			 		}
			 		else{//B操作 
			 			int rt=Min(TB);
			 			if(rt){
				 			LL D=((LL) W[Line[I].ID].C)*(W[Line[I].ID].B-max(W[Line[I].ID].A,K[rt].V));
				 			if(D > ANS){
				 				ANS=D;
				 				WID=Line[I].ID;
				 				AID=K[rt].ID;
				 			}	
			 			}
			 			
			 			Node X=Query(GetRank(W[Line[I].ID].A),GetRank(W[Line[I].ID].B));
			 			if(X.V){
				 			LL D=((LL) W[Line[I].ID].C)*X.V;
				 			if(D > ANS){
				 				ANS=D;
				 				WID=Line[I].ID;
				 				AID=X.ID;
				 			}
			 			}
			 		}
			 	}
			 	++I;
			}
		}
		printf("%I64d\n",ANS);
		if(ANS) printf("%d %d\n",AID,WID);
	}
return 0;
}

