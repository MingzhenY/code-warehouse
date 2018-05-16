#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 100007
#define M 1000000007
#define LL long long
using namespace std;
LL fac[maxn];
LL ten[maxn];
LL revfac[maxn];
const LL sign[2]={1,-1}; 
LL QuickPower(LL a,LL k){
	LL ANS=1;
	while(k){
		if(k&1) ANS=(ANS*a)%M;
		k>>=1;
		a=(a*a)%M;
	}
	return ANS;
}
LL C(LL n,LL k){
	if(k < 0) return 0;
	if(n < 0) return sign[k&1]*C(k-n-1,k);
	if(n < k) return 0;
	LL ANS=fac[n];
	ANS=(ANS*revfac[k])%M;
	ANS=(ANS*revfac[n-k])%M;
	return ANS;
}
void Init(){
	ten[0]=fac[0]=revfac[0]=1;
	for(int i=1;i<maxn;++i){
		fac[i]=(i*fac[i-1])%M;
		revfac[i]=QuickPower(fac[i],M-2);
		ten[i]=(10*ten[i-1])%M;
	}
}
int n,k;
char str[maxn];
LL Coef[maxn];
int main(void)
{
	Init();
	freopen("520E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		scanf("%s",str);
		int D=n-k-1;
		Coef[0]=C(n-2,k-1);
		for(int i=1;i<=D;++i) Coef[i]=(Coef[i-1]+ten[i]*C(n-i-2,k-1))%M;
		for(int i=D+1;i<n;++i) Coef[i]=Coef[i-1];
		for(int i=0;i<=D;++i) Coef[i]=(Coef[i]+ten[i]*C(n-i-2,k))%M;
		
		LL ANS=0;
		for(int i=0;i<n;++i){
			ANS=(ANS+Coef[n-i-1]*(str[i]-'0'))%M;
		}
		printf("%d\n",(int)ANS);
	}
return 0;
}














