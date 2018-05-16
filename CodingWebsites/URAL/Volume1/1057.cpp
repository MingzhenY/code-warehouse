#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
#define M 1000000007
using namespace std;
LL Pow(LL a,LL k){
	LL ANS=1;
	while(k){
		if(k&1) ANS=(ANS*a)%M;
		a=(a*a)%M;
		k>>=1;
	}
	return ANS;
}
LL fac[32];
LL revfac[32];
void init(){
	fac[0]=1;
	revfac[0]=1;
	for(int i=1;i<32;++i){
		fac[i]=(i*fac[i-1])%M;
		revfac[i]=Pow(fac[i],M-2);
	}
}
LL C(LL n,LL k){//0< n < 32
	if(n < k) return 0ll;
	LL ANS=fac[n];
	ANS=(ANS*revfac[k])%M;
	ANS=(ANS*revfac[n-k])%M;
	return ANS;
}

LL X,Y,K,B,RValue; 
LL Bpow[32];
void Binit(){
	Bpow[0]=1;
	for(int i=1;i<32;++i) Bpow[i]=(Bpow[i-1]*B)%((LL)M*M);
	switch(B){
		case 2:RValue=32;break;
		case 3:RValue=20;break;
		case 4:RValue=16;break;
		case 5:RValue=14;break;
		case 6:RValue=12;break;
		case 7:RValue=12;break;
		case 8:RValue=11;break;
		case 9:RValue=10;break;
		case 10:RValue=10;break;
	}
}
int brk(LL n){//将n在B进制下分解成 B^l + r 
	int L=0,R=RValue;
	while(L+1<R){
		LL Mid=(L+R)>>1;
		if(Bpow[Mid]<=n) L=Mid;
		else R=Mid;
	}
	return L;
}
LL F(LL n,LL k){//B进制下，[0,n)中，1的位数为k，其余位数为0的个数。 
	if(n==0) return 0;
	if(k==0) return 1;
	int l=brk(n);LL r=n-Bpow[l];
	return C(l,k)+F(min(Bpow[l],r),k-1);
}

int main(void)
{freopen("1057.txt","r",stdin); 
	init();
	while(cin>>X>>Y>>K>>B){
		Binit();
		LL ANS=F(Y+1,K)-F(X,K);
		cout<<ANS<<endl; 
	}
return 0;
}








