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
#define eps (1e-2)
using namespace std;
int dcmp(double d){
	return (d>-eps)-(d<eps);
}
double a[3002];
double c[3002];
double D;
int N;
int main(void)
{freopen("1047.txt","r",stdin); 
	while(cin>>N){
		cin>>a[0]>>D;
		FOR(i,N) scanf("%lf",&c[i]);
		double L=-2000,R=2000,M;
		
		start:
		M=(L+R)/2;
		a[1]=M;
		for(int i=2;i<=N+1;i++){
			a[i]=2*a[i-1]-a[i-2]+2*c[i-1];
		}
		if(a[N+1]<D) L=M;
		else R=M;
		if(!dcmp(a[N+1]-D)) goto end;
		goto start;
		end:
		printf("%.2f\n",M);
	}
return 0;
}








