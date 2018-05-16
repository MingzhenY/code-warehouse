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

int a;
int main(void)
{freopen("1493.txt","r",stdin); 
	while(~scanf("%d",&a)){
		char c[6];
		int d=a+1;int T=0;
		for(int i=0;i<6;i++){
			c[i]=d%10;d/=10;
		}
		if(c[0]+c[1]+c[2]==c[3]+c[4]+c[5]) T=1;
		d=a-1;
		for(int i=0;i<6;i++){
			c[i]=d%10;d/=10;
		}
		if(c[0]+c[1]+c[2]==c[3]+c[4]+c[5]) T=1;
		if(T) printf("Yes\n");
		else printf("No\n");
	}
	
	
	
	
return 0;
}








