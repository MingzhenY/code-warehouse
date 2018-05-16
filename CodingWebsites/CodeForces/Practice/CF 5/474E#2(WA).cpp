#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 100001
using namespace std;
int n,d;
//第一部分：离散化 
long long h[maxn];//原序H数组 
struct A{
	long long h;
	int i;
	bool operator<(const A &B)const{return h<B.h||h==B.h&&i<B.i;}
}H[maxn];//升序H数组 
map<long long,int> MP;
map<long long,int> MPSORT;

//第二部分：线段树
int N;
int st[maxn<<2];//符合条件的DP中的最大值 
int sti[maxn<<2];//最大值的新横坐标 
void init(){
	memset(st,0,sizeof(st));
	st[N]=st[2*N-1]=-1;
	for(int i=0;i<N;++i) sti[N+i]=i;
	for(int i=N-1;i>0;--i) {
		if(st[i<<1]>=st[i<<1|1]) st[i]=st[i<<1],sti[i]=sti[i<<1];
		else st[i]=st[i<<1|1],sti[i]=sti[i<<1|1];
	}
}
void query(int L,int R,int &MAX,int &I){
	MAX=0;I=0;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) if(MAX <st[s^1]) MAX=st[s^1],I=sti[s^1];//,printf("I=%d\n",I);
		if(t&1)  if(MAX <st[t^1]) MAX=st[t^1],I=sti[t^1];//,printf("I=%d\n",I);
	}
}
void update(int X,int C){
	int s=X+N;
	st[s]=C;s>>=1;
	while(s>0){
		if(st[s<<1]>st[s<<1|1]) st[s]=st[s<<1],sti[s]=sti[s<<1];
		else st[s]=st[s<<1|1],sti[s]=sti[s<<1|1];
		s>>=1;
	}
}

//第三部分：二分查找
int BS1(long long X){//找到小于等于X的最大新下标 
	int L,R,M;
	L=1,R=n+1;//左闭右开
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(H[M].h<=X) L=M;
	else R=M;
	goto begin;
	end:
	return L; 
} 
int BS2(long long X){//找到大于等于X的最小新下标 
	int L,R,M;
	L=0,R=n;//左开右闭 
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(H[M].h < X) L=M;
	else R=M;
	goto begin;
	end:
	return R; 
}  

//第四部分：DP 
int dp[maxn];
int pre[maxn];

int main(void)
{
	freopen("474E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&d)){
	//	printf("n=%d,d=%d\n",n,d);
		//离散化 
		MP.clear();MPSORT.clear();
		for(int i=1;i<=n;++i) scanf("%d",&h[i]),H[i].h=h[i],H[i].i=i;
		sort(H+1,H+n+1);
		for(int i=1;i<=n;++i) {
			if(!MP.count(H[i].h)) MP[H[i].h]=H[i].i;
			if(!MPSORT.count(H[i].h))MPSORT[H[i].h]=i;
		}
		//线段树
		N=1;while(N <n+2) N<<=1;
		init(); 
		//DP
		memset(dp,-1,sizeof(dp));
		memset(pre,0,sizeof(pre));
		dp[0]=0;
		for(int i=1;i<=n;++i){
			int ANS,ANS1,ANS2;
			int I,I1,I2;
			int D;
			D=BS1(h[i]-d);
			query(1,D,ANS1,I1);//printf("Q1\n");
			printf("新下标区间：(%d-%d) 值区间：(%lld-%lld)-ANS=%d\n",1,D,H[1].h,H[D].h,ANS1);
			
			D=BS2(h[i]+d);
			query(D,n,ANS2,I2);//printf("Q2\n");
			printf("新下标区间：(%d-%d) 值区间：(%lld-%lld)-ANS=%d\n",D,n,H[D].h,H[n].h,ANS2);
			if(ANS1>ANS2) ANS=ANS1,I=I1;
			else ANS=ANS2,I=I2;
			//printf("DDD\n");
			printf("第%d轮：最大连续:%d  前一个数：%d\n\n",i,ANS+1,H[I].i);
			
			dp[i]=ANS+1;pre[i]=H[I].i;
			
			//cout<<I<<endl;
			
			//cout<<"K"<<endl; 
			update(MPSORT[h[i]],dp[i]);
			//cout<<"K2"<<endl; 
			for(int i=1;i<=n;++i){
				int temp,t;
				query(i,i,temp,t);
				printf("%d:%d\n",i,temp);
			}
		} 
		int ANS=dp[1],ANSN=1;
		for(int i=2;i<=n;++i){
			if(dp[i]>ANS) {
				ANS=dp[i];
				ANSN=i;
			}
		} 
		printf("%d\n",ANS);
		vector<int>Q;
		for(int i=1;i<=ANS;++i) Q.push_back(ANSN),ANSN=pre[ANSN];
		printf("%d",Q[Q.size()-1]);
		for(int i=Q.size()-2;i>=0;--i) printf(" %d",Q[i]);
		cout<<endl;
	}
return 0;
}














