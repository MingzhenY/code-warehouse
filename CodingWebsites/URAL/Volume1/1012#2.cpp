#include <iostream>
#include <cstdio>
#include <cmath>

#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

double C(int a,int b);
int main(void)
{freopen("1012.txt","r",stdin); 
	int N,K;
	cin>>N>>K;
	
	double ANS=0;
	for(int a=0;a<N;a++){
		double _ANS=C(N-a,a);
		//OUT1(pow(M_E,_ANS));
		for(int i=0;i<N-a;i++){
			_ANS+=log(K-1);
		}
		ANS+=pow(M_E,_ANS);
	}
	
	printf("%.0f\n",ANS);
return 0;
}
double C(int a,int b){
	if(2*b<a) b=a-b;
	if(b==a) return 0;
	double ANS=0;
	for(int i=b+1;i<=a;i++){
		ANS*=log(i);
	}
	for(int i=2;i<=a-b;i++){
		ANS-=log(i);
	}
	return ANS;
}







