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
int prime[100000];
int p[10000];int Np;
int d[10000];
int main(void)
{freopen("1355.txt","r",stdin); 
	Np=0;memset(prime,-1,sizeof(prime));
	for(int i=2;i<100000;i++){
		if(~prime[i]) continue;
		for(int j=i;j<100000;j+=i){
			prime[j]=i;
		}
		p[Np++]=i;
	}
	int T;cin>>T;
	For(test,T){
		int a,b;
		scanf("%d%d",&a,&b);
		int ANS=0,ERR=0;
		For(i,Np) {
			int D=0;d[i]=0;
			while(a%p[i]==0) d[i]--,a/=p[i];
			while(b%p[i]==0) d[i]++,b/=p[i];
		}
		if(a>1){
			p[Np]=a;d[Np]=-1;Np++;
		}
		if(b>1){
			if(p[Np-1]==b) d[Np-1]++;
			else {
				p[Np]=b;d[Np]++;Np++;
			}
		}
		for(int i=0;i<Np;i++){
			if(d[i]>0) ANS+=d[i];
			if(d[i]<0){
				ANS=0;ERR=1;break;
			}
		}
		printf("%d\n",ANS+!ERR);
	}
return 0;
}








