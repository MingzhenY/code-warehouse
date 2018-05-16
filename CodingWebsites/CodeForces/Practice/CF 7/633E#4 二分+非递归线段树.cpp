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
//�ǵݹ��߶��� 
int Max[maxn<<2],Min[maxn<<2],N;
void Init(int n){//��ʼ�� 
	N = 1; while(N < n + 2) N <<= 1;
	for(int i = 2*N;--i;) Max[i]=0,Min[i]=10000000;
}
void UpdateMax(int X,int V){
	for(int s = N + X;s;s >>= 1) 
		if(V > Max[s]) Max[s] = V;
		else break;
}
void UpdateMin(int X,int V){
	for(int s = N + X;s;s >>= 1) 
		if(V < Min[s]) Min[s] = V;
		else break;
}
void Query(int L,int R,int &MaxV,int &MinC){//��ȡ�������ֵ��Сֵ 
	MaxV=0;MinC=10000000;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) MaxV=max(MaxV,Max[s^1]),MinC=min(MinC,Min[s^1]);
		if( t&1) MaxV=max(MaxV,Max[t^1]),MinC=min(MinC,Min[t^1]);
	}
}
int n,k,x;
int V[maxn];//��Ŀ����V 
int C[maxn];//��Ŀ����C 
int Q[maxn];//����ǰ��ÿ��L��Ӧ������Rֵ��Ӧ�Ĵ�
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
		Init(n);
		for(int i=1;i<=n;++i)	scanf("%d",&V[i]),UpdateMax(i,V[i]*=100);
		for(int i=1;i<=n;++i)   scanf("%d",&C[i]),UpdateMin(i,C[i]);
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

