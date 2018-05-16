#include <iostream>
#include <cstdio>
#include <cmath>

#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

void D();
int main(void)
{freopen("1001.txt","r",stdin); 
/*
	double  a;
	while(cin>>a){
		printf("%.4f\n",sqrt(a));
	}
*/
	D();
	
	
return 0;
}
void D(){
	double a;
	if(scanf("%lf",&a)==1){
		D();
		printf("%.4f\n",sqrt(a));
	} 
	
}







