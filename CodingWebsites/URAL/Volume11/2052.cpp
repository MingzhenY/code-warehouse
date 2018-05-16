#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
using namespace std;
int g[11][91];
void Init(){//there are g[t][k] numbers that have t digits and
			//  sum of digits is k  (including leading zero)
	memset(g,0,sizeof(g));
	g[0][0]=1;
	for(int t=1;t<=10;++t){
		for(int k=0;k<=9*t;++k){
			for(int i=0;i<=min(k,9);++i){
				g[t][k]+=g[t-1][k-i];
			}
		}
	}
}
int N,Dn,Digits[20];
int FindAll(int t,int k,int flag){//flag: is it bounded by N
	if(!flag||!t) return g[t][k];
	int I=Digits[t],ANS=0;
	for(int i=0;i<=min(I,k);++i) ANS+=FindAll(t-1,k-i,i==I);
	return ANS;
}
int Dig[20];
void Find(int t,int k,int rank,bool flag){//the rank-th number in g[t][k]
	if(!t) return;
	if(!flag){
		for(int i=0;i<=min(9,k);++i){
			if(rank <= g[t-1][k-i]){
				Dig[t]=i;
				Find(t-1,k-i,rank,false);
				return;
			}
			else rank-=g[t-1][k-i];
		}
	}
	else{
		int I=Digits[t],ANS=0;
		for(int i=0;i<=min(I,k);++i){
			int Num=FindAll(t-1,k-i,i==I);
			if(rank<=Num) {
				Dig[t]=i;
				Find(t-1,k-i,rank,i==I);
				return;
			}
			else rank-=Num;
		}
	}
}
int main(void)
{//freopen("2052.txt","r",stdin); 
	Init();
	while(~scanf("%d",&N)){
		Dn=0;
		while(N){
			Digits[++Dn]=N%10;
			N/=10;
		}
		int Sum=0,ANS=0;
		for(int k=1;k<=81;++k){
			int ALL=FindAll(Dn,k,true);
			if(!ALL) continue;
			int L,R,M,X;
			L=1;R=ALL+1;//[L,R) last Sum+i>=Value[i]
			while((L+1)^R){
				M=(L+R)>>1;
				Find(Dn,k,M,true);
				X=0;for(int i=Dn;i;--i) X=X*10,X+=Dig[i];
				if(Sum+M >=X) L=M;
				else R=M;
			}
			Find(Dn,k,L,true);
			X=0;for(int i=Dn;i;--i) X=X*10,X+=Dig[i];
			ANS+=X==Sum+L;
			Sum+=ALL;
		}
		printf("%d\n",ANS);
	}
return 0;
}
