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
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int N,M; 
int main(void)
{freopen("1139.txt","r",stdin); 
	while(cin>>N>>M){
		N-=1;M-=1;
		int D=gcd(M,N);
		M/=D;N/=D;
		int ANS=M+N-1;
		printf("%d\n",ANS*D);
	}
return 0;
}








