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
//��ɢ������ 
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
//�ǵݹ��߶��� 
int N; 
int Add[maxn<<3];//���串�Ǵ��� 
int P[maxn<<3];//�㸲�Ǵ��� 
void Build(int n){//���� 
	N=1;while(N < n+2) N <<= 1;
	memset(Add,0,sizeof(Add));
	memset(P,0,sizeof(P));
}
void Update(int L,int R){//�������
	//�߶θ��� 
	for(int s=N+L-1,t=N+R;s^t^1;s>>=1,t>>=1){
		if(~s&1) ++Add[s^1];
		if( t&1) ++Add[t^1]; 
	}
	//�����
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) ++P[s^1];
		if( t&1) ++P[t^1]; 
	}
}
void PushDown(){//�������б�� 
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
		//���� 
		for(int i=Rn=0;i<n;++i){
			scanf("%d%d",&l[i],&r[i]);
			Rank[++Rn]=l[i];
			Rank[++Rn]=r[i];
		}
		//��ɢ�� 
		SetRank();
		//���� 
		Build(Rn);
		//������ 
		for(int i=0;i<n;++i)
			Update(GetRank(l[i]),GetRank(r[i]));
		//���Ʊ�� 
		PushDown();
		//����� 
		int On=0,I=0;
		for(int i=1;i<=Rn;++i){
			if(Add[N+i]>=k){
				if(!On){//�����߶ε���˵㣬��¼ 
					l[++I]=Rank[i];
					On=1;
				}
			}
			else{
				if(On){//�����߶ε��Ҷ˵㣬��¼ 
					r[I]=Rank[i];
					On=0;
				}
				else{//ֻ���ڲ����߶θ���ʱ���Żῼ�ǵ��Ƿ񱻸�����k�λ����� 
					if(P[N+i]>=k){//����������k�λ����ϵĵ㣬��¼ 
						l[++I]=Rank[i];
						r[I]=Rank[i];
					}
				}
			}
		}
		//������ 
		printf("%d\n",I);
		for(int i=1;i<=I;++i){
			printf("%d %d\n",l[i],r[i]);
		}
	}
return 0;
}
