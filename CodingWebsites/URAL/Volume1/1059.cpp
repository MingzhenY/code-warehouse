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

int n; 
void F(int k){
	if(k) printf("X\n*\n%d\n+\n",k);
	else printf("%d\n",k);
}
int main(void)
{freopen("1059.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<=n;++i) F(i);
	}
return 0;
}








