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
//��һ���֣���ɢ�� 
long long h[maxn];//ԭ��H���� 
struct A{
	long long h;
	int i;
	bool operator<(const A &B)const{return h<B.h||h==B.h&&i<B.i;}
}H[maxn];//����H���� 
map<long long,int> MP;

//�ڶ����֣��߶���
int N,Kn;
int st[maxn<<2];//����������DP�е����ֵ 
int sti[maxn<<2];//���ֵ�ľɺ�����
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

//�������֣����ֲ���
int BS1(long long X){//�ҵ�С�ڵ���X��������±� ,�Ҳ�������0 
	if(X <H[1].h) return 0;
	int L,R,M;
	L=1,R=Kn+1;//����ҿ�
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(H[M].h <=X) L=M;
	else R=M;
	goto begin;
	end:
	return L; 
} 
int BS2(long long X){//�ҵ����ڵ���X����С���±� ,�Ҳ�������0 
	if(X>H[Kn].h) return 0;
	int L,R,M;
	L=0,R=Kn;//���ұ� 
	begin:
	if(L+1==R) goto end;
	M=(L+R)>>1;
	if(H[M].h < X) L=M;
	else R=M;
	goto begin;
	end:
	return R; 
}  

//���Ĳ��֣�DP 
int dp[maxn];//dp[i]��ʾ��i��β������������������г��� 
int pre[maxn];// dp[i]��ʾ��i��β������������������е�ǰһ��ֵ������ 

int main(void)
{
	freopen("474E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&d)){
		//��ɢ�� 
		MP.clear();
		for(int i=1;i<=n;++i) scanf("%I64d",&h[i]),H[i].h=h[i],H[i].i=i;
		sort(H+1,H+n+1);
		Kn=0;
		//�� long long ӳ�䵽 ��Ȼ�� ��ȥ���ظ��� 
		for(int i=1;i<=n;++i) if(!MP.count(H[i].h)) MP[H[i].h]=++Kn,H[Kn].h=H[i].h,H[Kn].i=H[i].i;
		//�߶���
		init(); 
		//DP
		for(int i=1;i<=n;++i) dp[i]=1,pre[i]=i;
		for(int i=1;i<=n;++i){
			int ANS,ANS1,ANS2,D;
			int D1=BS1(h[i]-d),D2=BS2(h[i]+d);
			if(D1) ANS1=query(1,D1,D1); else ANS1=0;//���ȡֵ��Χ 1�� h[i]-d ��dp���ֵ 
			if(D2) ANS2=query(D2,Kn,D2);else ANS2=0;// ���ȡֵ��Χ h[i]+d ���� ��dp���ֵ 
			if(ANS1 > ANS2) ANS=ANS1,D=D1;//���������������ֵ 
			else ANS=ANS2,D=D2;
			
			if(ANS>0){
				dp[i]=ANS+1;
				pre[i]=D;
			}
			update(MP[h[i]],dp[i],i);//������dp��������߶����� 
		}
		//������󳤶ȣ������·�� 
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














