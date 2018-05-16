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
using namespace std;
int maxprime[1000000];
int prime[100000];int pn;
int N;long long Q;int T=0;

bool isprime(long long Q){
	if(Q <1000000) return Q==maxprime[Q];
	For(i,pn) if(Q%prime[i]==0) return 0;
	return 1;
}
int main(void)
{freopen("1343.txt","r",stdin); 
	memset(maxprime,0,sizeof(maxprime));pn=0;
	for(int i=2;i<1000000;i++){
		if(maxprime[i]) continue;
		for(int j=i;j<1000000;j+=i) maxprime[j]=i;
		prime[pn++]=i;
	}
	while(cin>>N){
		//OUT1(N);
		if(N) cin>>Q;
		else Q=0;
		if(N==12){
			printf("%.12I64d\n",Q);
			continue;
		}
		while(N <6){
			Q=10*Q+rand()%10;
			N++;
		}
		int L=12-N,MAX=1;
		For(i,L) MAX*=10,Q*=10LL;
		int T=0;
		begin:
		for(int i=0;i<pn;i++){
			if(prime[i]>=MAX) {
				T=1;break;
			}
			long long D=Q+prime[i];
			if(isprime(D)){
				printf("%.12I64d\n",D);
				break;
			}
		}
		if(T){
			T=0;Q++;
			goto begin;
		}
	}
	
return 0;
}








