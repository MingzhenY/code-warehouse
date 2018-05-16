#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define maxn 100007 
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
//离散化 
int Rank[maxn<<1],Rn;
void SetRank(){//[1,n]
	sort(Rank+1,Rank+Rn+1);
	int I=1;
	for(int i=2;i<=Rn;++i) if(Rank[i]^Rank[i-1]) Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=Rn,M;//[L,R] first >=x
	while(L^R){
		M=(L+R)>>1;
		if(Rank[M]<x)L=M+1;
		else R=M;
	}
	return L;
}
//Segment Tree 
int Max[maxn<<3],N;
void PushDown(int rt){
	if(Max[rt]){
		if(Max[rt]>Max[rt<<1]) Max[rt<<1]=Max[rt];
		if(Max[rt]>Max[rt<<1|1]) Max[rt<<1|1]=Max[rt];
		Max[rt]=0;
	}
}
void Build(int n){
	N=1;while(N < n+2) N <<= 1;
	memset(Max,0,sizeof(Max));
}
void Update(int L,int R,int C){
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1 && C > Max[s^1]) Max[s^1]=C;
		if( t&1 && C > Max[t^1]) Max[t^1]=C;
	}
}
void Down(){for(int i=1;i<N;++i) PushDown(i);}
int PreH,Pn;
struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
}P[maxn<<2];
void GetPoints(){
	for(int i=1;i<=Rn;++i){
		if(Max[N+i]!=PreH){
			P[++Pn]=Point(Rank[i],PreH);
			P[++Pn]=Point(Rank[i],PreH=Max[N+i]);
		}
	}
}
//Information
int n;
int h[maxn],l[maxn],r[maxn];
int main(void)
{
	freopen("35E.txt","r",stdin); 
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,m;
	while(~scanf("%d",&n)){
		Rn=0;
		for(int i=0;i<n;++i){
			//输入 
			scanf("%d%d%d",&h[i],&l[i],&r[i]);
			//离散化 
			Rank[++Rn]=l[i];
			Rank[++Rn]=r[i];
		}
		//离散化 
		SetRank();
		//建树 
		Build(Rn);
		//更新 
		for(int i=0;i<n;++i)
			Update(GetRank(l[i]),GetRank(r[i])-1,h[i]);
		//下推标记 
		Down();
		//求值 
		PreH=Pn=0;
		GetPoints();
		//输出 
		printf("%d\n",Pn);
		for(int i=1;i<=Pn;++i) printf("%d %d\n",P[i].x,P[i].y);	
	}
return 0;
}

