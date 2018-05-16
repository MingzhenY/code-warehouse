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
int V[maxn];//��Ŀ����V 
int C[maxn];//��Ŀ����C 
int Q[maxn];//����ǰ��ÿ��L��Ӧ������Rֵ��Ӧ�Ĵ�

//Sparse Table 
int Max[maxn][21];
int Min[maxn][21];
void BuildSparseTable(){
	//���j=0��ֵ 
	for(int i=1;i<=n;++i) Max[i][0]=V[i],Min[i][0]=C[i];
	//����Sparse Table 
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
//���ֲ��� 
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
		//���ַ������ÿ��L��ʼ������ֵ
		for(int i=1;i<=n;++i) BinarySearch(i);
		//��С�������� 
		sort(Q+1,Q+n+1);
		//������ 
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

