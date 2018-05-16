#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 1000007
using namespace std;
//离散化部分 
int Rank[maxn<<1],Rn;
void SetRank(){
	sort(Rank+1,Rank+1+Rn);
	int I=1;
	for(int i=2;i<=Rn;++i) if(Rank[i]!=Rank[i-1]) Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=Rn,M;
	while(L^R){
		M=(L+R)>>1;
		if(Rank[M]<x) L=M+1;
		else R=M;
	} 
	return L;
}
//非递归线段树 
int N; 
int Add[maxn<<3];//区间覆盖次数 
int P[maxn<<3];//点覆盖次数 
void Build(int n){//建树 
	N=1;while(N < n+2) N <<= 1;
	memset(Add,0,sizeof(Add));
	memset(P,0,sizeof(P));
}
void Update(int L,int R){//区间更新
	//线段更新 
	for(int s=N+L-1,t=N+R;s^t^1;s>>=1,t>>=1){
		if(~s&1) ++Add[s^1];
		if( t&1) ++Add[t^1]; 
	}
	//点更新
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) ++P[s^1];
		if( t&1) ++P[t^1]; 
	}
}
void PushDown(){//下推所有标记 
	for(int i=1;i<N;++i){
		Add[i<<1]+=Add[i];
		Add[i<<1|1]+=Add[i];
		P[i<<1]+=P[i];
		P[i<<1|1]+=P[i];
	}
}
int n,k,l[maxn],r[maxn];
int main(void)
{
	freopen("612D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		//输入 
		for(int i=Rn=0;i<n;++i){
			scanf("%d%d",&l[i],&r[i]);
			Rank[++Rn]=l[i];
			Rank[++Rn]=r[i];
		}
		//离散化 
		SetRank();
		//建树 
		Build(Rn);
		//更新树 
		for(int i=0;i<n;++i)
			Update(GetRank(l[i]),GetRank(r[i]));
		//下推标记 
		PushDown();
		//计算答案 
		int On=0,I=0;
		for(int i=1;i<=Rn;++i){
			if(Add[N+i]>=k){
				if(!On){//碰到线段的左端点，记录 
					l[++I]=Rank[i];
					On=1;
				}
			}
			else{
				if(On){//碰到线段的右端点，记录 
					r[I]=Rank[i];
					On=0;
				}
				else{//只有在不被线段覆盖时，才会考虑点是否被覆盖了k次或以上 
					if(P[N+i]>=k){//遇到被覆盖k次或以上的点，记录 
						l[++I]=Rank[i];
						r[I]=Rank[i];
					}
				}
			}
		}
		//输出结果 
		printf("%d\n",I);
		for(int i=1;i<=I;++i){
			printf("%d %d\n",l[i],r[i]);
		}
	}
return 0;
}
