#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
map <long long,int> MP;
struct A{
	long long h;
	int i;
	bool operator<(const A &B)const{return h<B.h||h==B.h&&i<B.i;}
}H[100001];
long long h[100001];
int st[100001<<2];
int sti[100001<<2];
int N,n,d;
int dp[100001];
int pre[100001];
int preIndex[100001];
long long value[100001];
int query(int L,int R,int &X){
	int ANS=0;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) if(st[s^1]>ANS) ANS=st[s^1],X=sti[s^1];
		if(t&1) if(ANS<st[t^1]) ANS=st[t^1],X=sti[t^1];
	}
	return ANS;
}
void update(int X,int C){
	int T=X+N;
	st[T]=C;
	while(T>1){
		if(st[T^1]>st[T]) st[T>>1]=st[T^1],sti[T>>1]=sti[T^1];
		else st[T>>1]=st[T],sti[T>>1]=sti[T];
		T>>=1;
	}  
}
int BS1(long long x,int index,int i){
	int L,R,M;
	L=1,R=index+1;
	begin:
	//	printf("BS1:%d-%d\n",L,R);
		if(L+1==R) goto end;
		M=(L+R)>>1;
		if(value[M]<=h[i]-d) L=M;
		else R=M;
		goto begin;
	end:
	//	printf("End OF BS1\n");
	return L;
}
int BS2(long long x,int index,int i){
	int L,R,M;
	L=1,R=index+1;
	begin://printf("BS2:%d-%d\n",L,R);
		if(L+1==R) goto end;
		M=(L+R)>>1;
		if(value[M]<h[i]+d) L=M;
		else R=M;
		goto begin;
	end:	//printf("End OF BS2\n");
	return L;
}
int main(void)
{
	freopen("474E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&d)){
		for(int i=1;i<=n;++i) scanf("%I64d",&H[i].h),h[i]=H[i].h,H[i].i=i;
		sort(H,H+n);int index=0;
		MP[H[0].h]=++index;
		for(int i=1;i<n;++i){         /*
			H[i].h;//第i小的数 
			H[i].i;//原编号
			i;//新编号               */
			if(H[i].h!=H[i-1].h){
				MP[H[i].h]=++index;
				value[index]=H[i].h;
				preIndex[index]=i;
			}
		}
		N=1;while(N <n+2) N <<=1;
		memset(st,0,sizeof(st));
		memset(sti,0,sizeof(sti));
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		st[N]=st[2*N-1]=-1;
		for(int i=0;i< N;++i) sti[N+i]=i;
		for(int i=N-1;i>0;--i) {
			if(st[i<<1]>st[i>>1|1]) st[i]=st[i<<1],sti[i]=sti[i<<1];
			else st[i]=st[i<<1|1],sti[i]=sti[i<<1|1];
		}
		
		for(int i=0;i<n;++i){//printf("%d->\n",i);
			int X1,X2,X,ANS;
			int D1,D2;
			D1=query(1,BS1(h[i]-d,index,i),X1);
			D2=query(BS2(h[i]+d,index,i),index,X2);
			if(D1 > D2 ){
				ANS=D1;X=X1;
			}
			else {
				ANS=D2;X=X2;
			}
			dp[i]=ANS+1;
			pre[i]=preIndex[X];
			update(MP[h[i]],ANS+1);
		}
		
		printf("%d\n",dp[n]);
	}

		
return 0;
}














