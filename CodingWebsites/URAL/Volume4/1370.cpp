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

int N,M;
int a[1002];
int main(void)
{freopen("1370.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,N) scanf("%d",&a[i]);
		int T=M%N;
		for(int i=T;i<T+10;i++){
			printf("%d",a[i%N]);
		}
	}
return 0;
}








