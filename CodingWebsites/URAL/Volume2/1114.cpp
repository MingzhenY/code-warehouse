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
#define M 4294967291ll (2^32 - 5 is prime)(can caculate all the binomial coefficients that can fit in unsigned int)
#define LL unsigned long long
using namespace std;
LL fac[40],revfac[40];
LL Pow(LL a,LL k){
	LL A=1;
	while(k){
		if(k&1) A=(A*a)%M;
		a=(a*a)%M;
		k>>=1;
	}
	return A;
}
void init(){
	fac[0]=revfac[0]=1;
	for(int i=1;i<40;++i){
		fac[i]=(fac[i-1]*i)%M;
		revfac[i]=Pow(fac[i],M-2);
	}
}
LL C(int n,int r){
	LL ANS=fac[n];
	ANS=(ANS*revfac[r])%M;
	ANS=(ANS*revfac[n-r])%M;
	return ANS;
}
int N,A,B;
int main(void)
{freopen("1114.txt","r",stdin); 
	init();
	while(cin>>N>>A>>B){
		LL ANS=C(B+N,B)*C(A+N,A);
		cout<<ANS<<endl;
	}
return 0;
}








