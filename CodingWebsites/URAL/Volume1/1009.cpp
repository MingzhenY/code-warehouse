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

long long C(int a,int b);
int main(void)
{freopen("1009.txt","r",stdin); 
	int N,K;
	cin>>N>>K;
	
	long long ANS=0;
	for(int a=0;a<N;a++){
		long long _ANS=C(N-a,a);
		for(int i=0;i<N-a;i++){
			_ANS*=K-1;
		}
		ANS+=_ANS;
	}
	cout<<ANS<<endl;
return 0;
}
long long C(int a,int b){
	if(b>a||b<0) return 0;
	if(2*b<a) b=a-b;
	if(b==a) return 1;
	long long ANS=1;
	for(int i=b+1;i<=a;i++){
		ANS*=i;
	}
	for(int i=2;i<=a-b;i++){
		ANS/=i;
	}
	return ANS;
}







