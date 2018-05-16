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

double A,B; 
int main(void)
{freopen("1200.txt","r",stdin); 
	while(cin>>A>>B){
		int K;cin>>K;
		int a=0,b=0;double ANS=0;
		for(int i=0;i<=K;i++){
			//for(int j=max(0,T-3);j<=min(K-i,T+3);j++){
			for(int j=0;j<=K-i;j++){
				double D=i*A+j*B-i*i-j*j;
				if(D>ANS){
					ANS=D;
					a=i;b=j;
				}
			}
		}
		printf("%.2f\n",ANS);
		printf("%d %d\n",a,b);
	}
	
return 0;
}








