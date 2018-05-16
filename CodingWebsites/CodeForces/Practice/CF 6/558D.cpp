/*
将祖先节点的区间映射到叶节点。
将 在区间[L,R) 转换成->  不在区间[1,L) 和 不在区间[R,(1<<h)+1) 
于是全部范围都是叶节点的范围，求最后的叶节点就好了。 
于是，题目变为，就是将一个全1序列，不停的把某些区间变为全零，问最后剩下几个1 
1的数量略多，所以要离散化。 
用线段树维护就好。
注意：L>1时，才需要插入[1,L)区间 不然会出错。 
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
#define maxn 200007 
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
LL Left[maxn],Right[maxn],N;//区间信息 [Left,Right)
LL Rank[maxn<<1],Rn;//离散化
int GetRank(LL x){
	int L=0,R=Rn+1,M;//[L,R) last <=x
	while((L+1)^R){
		M=(L+R)>>1;
		if(Rank[M]<=x) L=M;
		else R=M;
	}
	return L;
} 
void AddLine(LL L,LL R){//[L,R)
	Left[N]=L;Right[N++]=R;
	Rank[Rn++]=L;Rank[Rn++]=R;
}
int h,q;
//线段树
LL Sum[maxn<<2];
void Build(int l,int r,int rt){
	if(l==r){
		Sum[rt]=Rank[l]-Rank[l-1];
		return;
	}
	int m=(l+r)>>1;
	Build(ls);
	Build(rs);
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1]; 
}
void Update(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){Sum[rt]=0;return;}
	if(!Sum[rt]) return;
	int m=(l+r)>>1;
	if(L <= m) Update(L,R,ls);
	if(R >  m) Update(L,R,rs);
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
}
int Search(int l,int r,int rt){
	if(l==r) return l;
	int m=(l+r)>>1;
	if(Sum[rt<<1]) return Search(ls);
	else return Search(rs);
}
int main(void)
{
	freopen("558D.txt","r",stdin); 
	ios::sync_with_stdio(false); 
	while(cin>>h>>q){
		N=Rn=0;LL A=1;for(int i=1;i<h;++i) A <<=1;
		for(int i=0;i<q;++i){
			int x,ans;
			LL L,R;
			cin>>x>>L>>R>>ans;
			if(ans){
				LL DL=(L << (h-x))-A+1,DR=((R+1) << (h-x))-A+1;
				//[DL,DR)
				if(DL >  1) AddLine(1,DL);
				if(DR <= A) AddLine(DR,A+1);
			}
			else AddLine((L << (h-x))-A+1,((R+1) << (h-x))-A+1);
		}
		Rank[Rn++]=1;Rank[Rn++]=A+1;
		//离散化 
		sort(Rank,Rank+Rn);
		int I=0;
		for(int i=1;i<Rn;++i) if(Rank[i]!=Rank[i-1]) Rank[++I]=Rank[i];
		Rn=I;
		//线段树 
		Build(1,Rn,1);
		for(int i=0;i<N;++i) Update(GetRank(Left[i])+1,GetRank(Right[i]),1,Rn,1);
		//输出 
		if(Sum[1]){
			if(Sum[1]>1) cout<<"Data not sufficient!"<<endl;
			else {
				int X=Search(1,Rn,1);
				if(Rank[X]-Rank[X-1]==1) cout<<(Rank[X-1]+A-1)<<endl;
				else cout<<"Data not sufficient!"<<endl;
			}
		}
		else cout<<"Game cheated!"<<endl;
	}
return 0;
}

