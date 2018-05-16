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

//第二部分：线段树
int N,Kn;
int st[maxn<<2];//符合条件的DP中的最大值 
int sti[maxn<<2];//最大值的旧横坐标
void init(){
	N=1;while(N <Kn+2) N <<=1;
	memset(st,0,sizeof(st));
	memset(sti,0,sizeof(sti)); 
}
int query(int L,int R,int &I){
	int MAX=0;I=0;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) if(MAX <st[s^1]) MAX=st[s^1],I=sti[s^1];
		if(t&1)  if(MAX <st[t^1]) MAX=st[t^1],I=sti[t^1];
	}
	return MAX;
}
void update(int X,int C,int Oldi){
	int s=X+N;
	st[s]=C;sti[s]=Oldi;s>>=1;
	while(s>0){
		if(st[s<<1]>st[s<<1|1]) st[s]=st[s<<1],sti[s]=sti[s<<1];
		else st[s]=st[s<<1|1],sti[s]=sti[s<<1|1];
		s>>=1;
	}
}

//第三部分：二分查找
int BS1(long long X){//找到小于等于X的最大新下标 ,找不到返回0 
	if(X <H[1].h) return 0;
	int L,R,M;
	L=1,R=Kn+1;//左闭右开
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(H[M].h <=X) L=M;
	else R=M;
	goto begin;
	end:
	return L; 
} 
int BS2(long long X){//找到大于等于X的最小新下标 ,找不到返回0 
	if(X>H[Kn].h) return 0;
	int L,R,M;
	L=0,R=Kn;//左开右闭 
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
int dp[maxn];//dp[i]表示以i结尾的最长符合条件的子序列长度 
int pre[maxn];// dp[i]表示以i结尾的最长符合条件的子序列的前一个值的坐标 

int main(void)
{
	freopen("474E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&d)){
		//离散化 
		MP.clear();
		for(int i=1;i<=n;++i) scanf("%I64d",&h[i]),H[i].h=h[i],H[i].i=i;
		sort(H+1,H+n+1);
		Kn=0;
		//将 long long 映射到 自然数 （去除重复） 
		for(int i=1;i<=n;++i) if(!MP.count(H[i].h)) MP[H[i].h]=++Kn,H[Kn].h=H[i].h,H[Kn].i=H[i].i;
		//线段树
		init(); 
		//DP
		for(int i=1;i<=n;++i) dp[i]=1,pre[i]=i;
		for(int i=1;i<=n;++i){
			int ANS,ANS1,ANS2,D;
			int D1=BS1(h[i]-d),D2=BS2(h[i]+d);
			if(D1) ANS1=query(1,D1,D1); else ANS1=0;//求出取值范围 1到 h[i]-d 的dp最大值 
			if(D2) ANS2=query(D2,Kn,D2);else ANS2=0;// 求出取值范围 h[i]+d 以上 的dp最大值 
			if(ANS1 > ANS2) ANS=ANS1,D=D1;//对两个区间求最大值 
			else ANS=ANS2,D=D2;
			
			if(ANS>0){
				dp[i]=ANS+1;
				pre[i]=D;
			}
			update(MP[h[i]],dp[i],i);//将本次dp结果加入线段树。 
		}
		//搜索最大长度，并输出路径 
		int ANS=0,ANSN;
		for(int i=1;i<=n;++i) if(dp[i]>ANS) ANS=dp[i],ANSN=i;
		printf("%d\n",ANS);
		vector<int> V;
		while(pre[ANSN]!=ANSN){
			V.push_back(ANSN);
			ANSN=pre[ANSN]; 
		}
		printf("%d",ANSN);
		for(int i=V.size()-1;i>=0;--i) printf(" %d",V[i]);
		cout<<endl;
	}
return 0;
}














