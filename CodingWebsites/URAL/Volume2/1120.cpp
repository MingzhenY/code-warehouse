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
#define eps 1e-8
bool Isqare(long long a){
	long long b=(long long)sqrt(a+eps);
	return b*b==a;
}
int main(void)
{freopen("1120.txt","r",stdin); 
	long long N;
	while(cin>>N){
		//OUT1(N);
		for(long long i=1;i<4*N;i+=2){
			if(Isqare(i*i+8*N)){
				//OUT2(i,(long long)i*i+8*N);
				printf("%d ",(i+1)/2);
				cout<<(((long long)sqrt((double) i*i+8*N+eps)-i)/2)<<endl;
				break;
			}
		}	
	}
return 0;
}








