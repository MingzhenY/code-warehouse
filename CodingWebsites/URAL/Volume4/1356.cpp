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

int prime[1000000];
int P[100000],Pn;
bool IsPrime(int k){
	if(k<1000000) return k==prime[k];
	for(int i=0;i<3402;i++){
		if(k%P[i]==0) return 0;
	}
	return 1;
}
int main(void)
{freopen("1356.txt","r",stdin); 
	memset(prime,-1,sizeof(prime));Pn=0;
	for(int i=2;i<1000000;i++){
		if(~prime[i]) continue;
		for(int j=i;j<1000000;j+=i){
			prime[j]=i;
		}
		P[Pn++]=i;
	}
	int T,N;cin>>T;
	FOR(test,T){
		scanf("%d",&N);//OUT1(N);
		if(IsPrime(N)){
			printf("%d\n",N);
			continue;
		}
		if(N&1){
			if(IsPrime(N-2)) {
				printf("%d %d\n",2,N-2);
				continue;
			}
			N-=3;
			printf("3 ");
		}
		For(i,Pn){
			if(IsPrime(N-P[i])){
				printf("%d %d\n",P[i],N-P[i]);
				break;
			}
		}
	}
return 0;
}








