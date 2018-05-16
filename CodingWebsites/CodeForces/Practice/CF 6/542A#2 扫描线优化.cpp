/*
561 ms	41500 KB
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
//非递归线段树 -- 单点修改，维护区间最大值 
//Segment Tree 
struct Node{
	int V,ID;
	Node():V(0),ID(0){}
	Node(int V,int ID):V(V),ID(ID){}
	bool operator <(const Node &B)const{return V < B.V || V==B.V && ID < B.ID;}
	bool operator ==(const Node &B)const{return V==B.V&&ID==B.ID;}
}ST[maxn<<4];
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
		
		Build(Rn);//线段树初始化 
		LL ANS=0;int I=0,AID,WID;
		int RM=0,RID=0;
		for(int i=1;i<=Rn;++i){
			if(Rank[i]>RM) RM=Rank[i],RID=0;
			while(I < Ln && Line[I].X == i){
			 	if(Line[I].TYPE){//更新 
			 		if(Line[I].IN){//L操作 
			 			if(A[Line[I].ID].R>RM) RM=A[Line[I].ID].R,RID=Line[I].ID;
			 		}
			 		else{//R操作 
			 			Update(GetRank(A[Line[I].ID].L),Node(A[Line[I].ID].R-A[Line[I].ID].L,Line[I].ID));
			 		}
			 	}
			 	else{//计算 
			 		if(Line[I].IN){//A操作 
			 			if(RID){
				 			LL D=((LL) W[Line[I].ID].C)*(min(RM,W[Line[I].ID].B)-W[Line[I].ID].A);
					 		if(D > ANS){
					 			ANS=D;
					 			WID=Line[I].ID;
					 			AID=RID;
					 		}	
			 			}
			 		}
			 		else{//B操作 
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
		I=Ln-1;int LM=Rank[Rn],LID=0;
		for(int i=Rn;i>=1;--i){
			if(Rank[i]<LM) LM=Rank[i],LID=0;
			while(I>=0 && Line[I].X == i){
			 	if(Line[I].TYPE){//更新 
			 		if(!Line[I].IN) {//R操作 
			 			if(A[Line[I].ID].L <LM) LM=A[Line[I].ID].L,LID=Line[I].ID;
			 		}
			 	}
			 	else{//计算 
			 		if(!Line[I].IN){//B操作 
			 			if(LID){
				 			LL D=((LL) W[Line[I].ID].C)*(W[Line[I].ID].B-max(W[Line[I].ID].A,LM));
					 		if(D > ANS){
					 			ANS=D;
					 			WID=Line[I].ID;
					 			AID=LID;
					 		}	
			 			}
			 		}
			 	}
			 	--I;
			}
		}
		printf("%I64d\n",ANS);
		if(ANS) printf("%d %d\n",AID,WID);
	}
return 0;
}

