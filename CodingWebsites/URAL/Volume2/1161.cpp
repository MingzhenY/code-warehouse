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

int N;
double a[100];
int main(void)
{freopen("1161.txt","r",stdin); 
	cin>>N;
	For(i,N) cin>>a[i];
	sort(a,a+N);
	double ANS=a[N-1];
	for(int i=N-2;i>=0;i--){
		ANS=2*sqrt(ANS*a[i]);
	}
	printf("%.2f",ANS);
	
return 0;
}








