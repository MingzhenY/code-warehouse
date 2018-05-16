#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include<iomanip>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LD long double
#define maxn 1000007
using namespace std;
int n,k,x;
int V[maxn];//题目数据V 
int C[maxn];//题目数据C 
int Q[maxn];//排序前：每个L对应的最优R值对应的答案

//Sparse Table 
int Max[maxn][21];
int Min[maxn][21];
void BuildSparseTable(){
	//填好j=0的值 
	for(int i=1;i<=n;++i) Max[i][0]=V[i],Min[i][0]=C[i];
	//计算Sparse Table 
	for(int j=1;(1<<j) <= n;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
		}
	}
}
void Query(int L,int R,int &MaxV,int &MinC){
	int k = int(log2(R-L+1.0));
	MaxV=max(Max[L][k],Max[R-(1<<k)+1][k]);
	MinC=min(Min[L][k],Min[R-(1<<k)+1][k]);
}
//二分查找 
void BinarySearch(int X){
	int L=X,R=n+1,M,MaxV,MinC;//[L,R) last Max <= Min
	while((L+1)^R){
		M = (L+R)>>1;
		Query(X,M,MaxV,MinC);
		if(MaxV <= MinC) L = M;
		else R = M;
	}
	Query(X,L,MaxV,MinC);
	Q[X]=min(MaxV,MinC);
	if(L < n) Q[X]=max(Q[X],min(max(MaxV,V[L+1]),min(MinC,C[L+1])));
}
int main(void)
{
	freopen("633E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;++i)	scanf("%d",&V[i]),V[i]*=100;
		for(int i=1;i<=n;++i)   scanf("%d",&C[i]);
		BuildSparseTable();
		//二分法计算从每个L开始的最优值
		for(int i=1;i<=n;++i) BinarySearch(i);
		//从小到大排序 
		sort(Q+1,Q+n+1);
		//计算结果 
		LD ANS=(LD)(0);
		LD CF=(LD)k/n;
		for(int t=1;t <= n-k+1;++t){
			ANS+=CF*Q[t];
			CF*=(LD)(n-k-t+1)/(n-t);
		}
		cout<<fixed<<setprecision(7)<<ANS<<endl;
	}
return 0;
}

