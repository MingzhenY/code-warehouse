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

int i,j,n;
long double Fi,Fj; 
const long double a=(1+sqrt((long double)5.0))/2;
const long double b=(1-sqrt((long double)5.0))/2;
int main(void)
{freopen("1133.txt","r",stdin); 
	while(cin>>i>>Fi>>j>>Fj>>n){
		int mind=min(i,min(j,n));
		i-=mind;j-=mind;n-=mind;
		long double ai=pow(a,(long double)i),aj=pow(a,(long double)j),an=pow(a,(long double)n);
		long double bi=pow(b,(long double)i),bj=pow(b,(long double)j),bn=pow(b,(long double)n);
		long double A=(Fi*bj-Fj*bi)/(ai*bj-aj*bi);
		long double B=(Fj*ai-Fi*aj)/(ai*bj-aj*bi);
		long double Fn=A*an+B*bn;
		long long ANS=(long long) round(Fn);
		cout<<ANS<<endl;
	}
return 0;
}








