#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;


int main(void)
{freopen("2001.txt","r",stdin); 
	int a[3],b[3];
	for(int i=0;i<3;++i) scanf("%d%d",&a[i],&b[i]); 
	printf("%d %d\n",a[0]-a[2],b[0]-b[1]);
	
	
	
return 0;
}








