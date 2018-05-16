/*
	499 ms	15668 KB
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 500007
using namespace std;
int Rank[maxn],Rn;
void SetRank(){//[1..Rn]->[1..I]
	int I=1;
	sort(Rank+1,Rank+Rn+1);
	for(int i=2;i<=Rn;++i) if(Rank[i]^Rank[i-1]) Rank[++I]=Rank[i];
	Rn=I;
}
int GetRank(int x){
	int L=1,R=Rn,M;//[L,R] first >= x
	while(L^R){
		M=(L+R)>>1;
		if(Rank[M] < x)L=M+1;
		else R=M;
	}
	return L;
}
int Max[maxn<<2],N;
int Build(int n){//���� 
	N=1;while(N < n+2) N <<= 1; 
	memset(Max,-1,sizeof(Max));
}
void Update(int L,int x){//�� x ���� L ���ֵ 
	for(int s=N+L;s;s>>=1){
		if(x > Max[s]) Max[s]=x;
		else break;
	}
}
bool Search(int L,int y){//����(L,Rn]��û��ֵ���� y 
	for(int s=N+L;s^1;s>>=1){
		if(~s&1){
			if(Max[s^1] > y) return true;
		}
	}
	return false;
}
int n;
struct Point{
	int x,y,z;
	Point(){}
	Point(int x,int y,int z):x(x),y(y),z(z){}
	bool operator <(const Point &B)const{return z>B.z||z==B.z&&y>B.y||z==B.z&&y==B.y&&x>B.x;}
}P[maxn];
int main(void)
{
	freopen("12D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		Rn=0;
		for(int i=0;i<n;++i){
			scanf("%d",&P[i].x);
			Rank[++Rn]=P[i].x;
		}
		for(int i=0;i<n;++i) scanf("%d",&P[i].y);
		for(int i=0;i<n;++i) scanf("%d",&P[i].z);
		//�������� 
		sort(P,P+n);
		//��ɢ�� 
		SetRank();
		//���� 
		Build(Rn);
		int ANS=0;
		int Z,Zi=0;
		int I=0;
		while(I<n){//ɨ�� 
			for(int i=Zi;i<I;++i){//�����߶��� 
				Update(GetRank(P[i].x),P[i].y);
			}
			Z=P[I].z;//��¼����Zֵ 
			Zi=I;//��¼������㣬��������߶��� 
			//���� 
			while(I < n && P[I].z==Z){ 
				ANS+=Search(GetRank(P[I].x),P[I].y);
				++I;
			}
		}
		printf("%d\n",ANS);
	}
return 0;
}
