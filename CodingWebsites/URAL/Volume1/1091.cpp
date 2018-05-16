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

int C(int n,int k){
	if(n<k) return -100;
	int Max=max(n-k,k),Min=min(n-k,k);
	double ANS=0.0;
	for(int i=Max+1;i<=n;++i) ANS+=log2(i);
	for(int i=Min;i>=2;--i) ANS-=log2(i);
	return pow(2,ANS)+0.5;
}
int prime[100],isprime[100],mu[100],cnt;
void Mobius(int n)
{
	int i,j;
    cnt=0;mu[1]=1;
    for(i=2;i<=n;i++){
    	if(!isprime[i]){
            prime[cnt++]=i;
            mu[i]=-1;
        }
        for(j=0;j<cnt && i*prime[j]<=n;j++){
            isprime[i*prime[j]]=1;
            if(i%prime[j])
                mu[i*prime[j]]=-mu[i];
            else {mu[i*prime[j]]=0;break;}
        }
	}
}
int K,S;
int F(int x){
	int ANS=0;
	if(S/x>=K) ANS=C(S/x,K);
	return ANS;
}
int f(int x){
	int ANS=0;
	for(int d=x;d <=S;d+=x){
		ANS+=mu[d/x]*F(d);
	}
	return ANS;
}
int main(void)
{freopen("1091.txt","r",stdin); 
	Mobius(100);
	while(cin>>K>>S){
		int ANS=0;
		for(int i=2;i<S;++i){
			ANS+=f(i);
		}
		//OUT3(K,S,ANS);
		if(ANS>10000) ANS=10000;
		cout<<ANS<<endl;
	}
return 0;
}








