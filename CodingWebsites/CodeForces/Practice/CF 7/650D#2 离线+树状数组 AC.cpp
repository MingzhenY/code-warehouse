/*  873 ms	39200 KB */ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <list>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 400007
using namespace std;
struct Node{
	int id,v;
	Node(){}
	Node(int id,int v):id(id),v(v){}
};
list<Node> List[maxn];
//离散化 
int Rank[maxn<<1],Rn;
void SetRank(int n){
	sort(Rank+1,Rank+n+1);
	Rn = 1;
	for(int i=2;i<=n;++i)
		if(Rank[i]^Rank[i-1])
			Rank[++Rn]=Rank[i];
}
int GetRank(int x){
	int L=1,R=Rn,M;//[L,R] first >= x
	while(L^R){
		M = (L+R)>>1;
		if(Rank[M] < x) L = M + 1;
		else R = M;
	}
	return L;
}
//题目数据 
int n,m,a[maxn],b[maxn],k;
int h[maxn];

//LIS部分
int LIS_L[maxn],LIS_R[maxn],Len[maxn],Ln;
int Test_L(int v){
	int L=0,R=Ln+1,M;//[L,R)  last < v
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(Len[M] < v) L = M;
		else R = M;
	}
	return L;
}
int Test_R(int v){
	int L=0,R=Ln+1,M;//[L,R) last > v
	while(L + 1 < R){
		M = (L + R) >> 1;
		if(Len[M] > v) L = M;
		else R = M;
	}
	return L;
}
void LIS(){
	Len[0]=Ln=0;
	for(int i=1;i<=n;++i){
		LIS_L[i] = Test_L(h[i]) + 1;
		if(Ln < LIS_L[i]) Len[++Ln] = h[i];
		else Len[LIS_L[i]]=min(Len[LIS_L[i]],h[i]);
	}
	k = Ln;//记录最长LIS 
	Len[0]=1000000001;Ln=0;
	for(int i=n;i>=1;--i){
		LIS_R[i] = Test_R(h[i]) + 1;
		if(Ln < LIS_R[i]) Len[++Ln] = h[i];
		else Len[LIS_R[i]]=max(Len[LIS_R[i]],h[i]);
	}
}
//树状数组
int BIT_L[maxn<<1],BIT_R[maxn<<1];
void Add_L(int x,int v){
	while(x <= Rn){
		BIT_L[x]=max(BIT_L[x],v);
		x+=x&-x;
	}
}
int Query_L(int x){
	int ANS = 0;
	while(x > 0){
		ANS = max(ANS,BIT_L[x]);
		x-=x&-x;
	}
	return ANS;
}
void Add_R(int x,int v){
	while(x > 0){
		BIT_R[x]=max(BIT_R[x],v);
		x-=x&-x;
	}
}
int Query_R(int x){
	int ANS = 0;
	while(x <= Rn){
		ANS = max(ANS,BIT_R[x]);
		x+=x&-x;
	}
	return ANS;
}
int Count[maxn];//每种位置的数的数量
int pos[maxn];//第i个数在LIS中的位置，0表示不在LIS中 
int L[maxn],R[maxn];//记录左右的答案 
int main(void)
{
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) scanf("%d",&h[i]),Rank[i]=h[i],List[i].clear();
		//读取询问
		for(int i=1;i<=m;++i){
			scanf("%d%d",&a[i],&b[i]);
			List[a[i]].push_back(Node(i,b[i]));
			Rank[n+i]=b[i];
		}
		//离散化
		Rank[n+m+1]=0;Rank[n+m+2]=1000000001;
		SetRank(n+m+2);
		
		//建立LIS数组 
		LIS();
		//计算Count和pos 
		memset(Count,0,sizeof(Count));
		for(int i=1;i<=n;++i){
			int L = LIS_L[i],R = LIS_R[i]; 
			if(L+R==k+1){
				++Count[pos[i]=L];
			}
			else pos[i]=0;
		}
		//开始计算
		memset(BIT_L,0,sizeof(BIT_L));
		for(int i=1;i<=n;++i){
			for(list<Node>::iterator it=List[i].begin();it!=List[i].end();++it){
				L[it->id]=Query_L(GetRank(it->v)-1);
			}
			Add_L(GetRank(h[i]),LIS_L[i]);
		}
		memset(BIT_R,0,sizeof(BIT_R));
		for(int i=n;i>=1;--i){
			for(list<Node>::iterator it=List[i].begin();it!=List[i].end();++it){
				R[it->id]=Query_R(GetRank(it->v)+1);
			}
			Add_R(GetRank(h[i]),LIS_R[i]);
		}
		for(int i=1;i<=m;++i){
			int ANS1 = 1 + L[i]+R[i];
			int ANS2 = Count[pos[a[i]]]!=1?k:k-1;
			printf("%d\n",max(ANS1,ANS2));
		}
	}
return 0;
}
