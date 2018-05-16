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

int prime[10001];
int p[6];int Np;
int num[6];
int ans[10001];
int F(int k){
	Np=0;
	while(k>1){
		//OUT1(k);
		//OUT3(Np,p[Np-1],prime[k]);
		if(Np>0&&(p[Np-1]==prime[k])) num[Np-1]++;
		else p[Np]=prime[k],num[Np]=1,Np++;
		k/=prime[k];
	}
	int ANS=1;
	For(i,Np) ANS*=num[i]+1;
	return (ANS+1)/2;
}
int main(void)
{freopen("1157.txt","r",stdin); 
	memset(prime,-1,sizeof(prime));
	for(int i=2;i<10001;i++){
		if(~prime[i]) continue;
		for(int j=i;j<10001;j+=i){
			prime[j]=i;
		}
	}
									
	ans[0]=0;
	FOR(i,10000){
		ans[i]=F(i);
	}
	int N,M,K;
	while(cin>>M>>N>>K){
		int T=0;
		for(int i=K;i<=10000;i++){
			if(ans[i]==N&&ans[i-K]==M){
				printf("%d\n",i);
				T=1;
				break;
			}
		}
		if(!T){
			printf("0\n");
		}
	}
return 0;
}








