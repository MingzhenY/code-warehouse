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

double GetD(){
	int a,b;double D;
	scanf("%d.%d\n",&a,&b);
	D=a+b/60.0;
	return D;
} 
int main(void)
{freopen("1070.txt","r",stdin); 
	double T1=GetD(),T2=GetD(),T3=GetD(),T4=GetD(),D1,D2;
	//OUT2(T1,T2);OUT2(T3,T4);
	D1=T2>T1?T2-T1:T2+24-T1;
	D2=T4>T3?T4-T3:T4+24-T3;
	//OUT2(D1,D2);
	double D=abs(D1-D2)/2;
	int ANS=floor(D+0.51);
	cout<<ANS<<endl;
return 0;
}








