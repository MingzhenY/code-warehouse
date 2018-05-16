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
#define LL int
using namespace std;

int p[1000000];
int rp[100000];int Nrp;
int prime[40];int Np;
int num[40];
int n; 
int ANS[1000];int ANSN;
void gcd(LL a,LL b,LL &d,LL&x,LL&y){
	if(!b){d=a;x=1;y=0;}
	else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
void dfs(int i,int m){
	if(i==Np){
		int d,x,y;
		//OUT1(m);
		gcd(m,n/m,d,x,y);
		if(d==1){
			int a=x,b=y;
			while(1){
				int D=max(abs(m*a),abs(n/m*b));
				if(D>=n) break;
				int T=1;
				For(k,ANSN)if(D==ANS[k]) T=0;
				if(T) ANS[ANSN++]=D; 
				a+=n/m;b-=m;
			}
			a=x,b=y;
			while(1){
				int D=max(abs(m*a),abs(n/m*b));
				if(D>=n) break;
				int T=1;
				For(k,ANSN)if(D==ANS[k]) T=0;
				if(T) ANS[ANSN++]=D; 
				a-=n/m;b+=m;
			}
			
			//printf("\t");OUT1(D);
			
		}
		return;
	}
	int T=1;
	for(int k=0;k<=num[i];k++){
		dfs(i+1,m*T);
		T*=prime[i];
	}
}
int main(void)
{freopen("1204.txt","r",stdin); 
	Nrp=0;
	memset(p,-1,sizeof(p));
	for(int i=2;i<1000000;i++){
		if(~p[i]) continue;
		rp[Nrp++]=i;
		for(int j=i;j<1000000;j+=i) p[j]=i;
	}
	int N;cin>>N;
	FOR(cases,N){
		scanf("%d",&n);
		Np=0;
		int tn=n;
		For(i,Nrp){
			if(tn%rp[i]==0){
				prime[Np]=rp[i];num[Np]=0;
				while(tn%rp[i]==0) tn/=rp[i],num[Np]++;
				Np++;
			}
		}
		if(tn>1) {
			prime[Np]=tn;num[Np++]=1;
		}
		/*
		For(i,Np){
			printf("%d:%d\n",prime[i],num[i]);
		}
		*/
		ANSN=2;
		ANS[0]=0;ANS[1]=1;
		dfs(0,1);
		sort(ANS,ANS+ANSN);
		For(i,ANSN) {
			printf("%d",ANS[i]);
			if(i==ANSN-1) printf("\n");
			else printf(" ");
		}
	}
return 0;
}








