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

struct Block{
	int end;
	Block():end(0){}
}B[30001];
int main(void)
{freopen("1037.txt","r",stdin); 
	int a,b;char op; 
	while(~scanf("%d %c",&a,&op)){
		if(op=='.') {
			scanf("%d",&b);
			//OUT3(a,b,B[b].end);
			if(B[b].end <=a) printf("-\n");
			else printf("+\n"),B[b].end=a+600;
		}
		else{
			int I;
			FOR(i,30000){
				if(B[i].end <=a){
					I=i;break;
				}
			}
			B[I].end=a+600;
			printf("%d\n",I);
		}
	}
return 0;
}








