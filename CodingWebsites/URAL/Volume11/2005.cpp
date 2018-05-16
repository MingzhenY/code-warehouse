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

int plan[4][5]={
{0,2,3,1,4},
{0,3,2,1,4},
{0,2,1,3,4},
{0,1,2,3,4}
};
int main(void)
{freopen("2005.txt","r",stdin); 
	int a[5][5]; 
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			scanf("%d",&a[i][j]);
		}
	}
	int Min=0x7fffffff,MinI;
	for(int i=0;i<4;++i){
		int ANS=0;
		for(int j=0;j<4;++j) ANS+=a[plan[i][j]][plan[i][j+1]];
		if(ANS<Min){
			Min=ANS;
			MinI=i;
		}
	}
	printf("%d\n",Min);
	for(int i=0;i<5;++i){
		printf("%d",plan[MinI][i]+1);
		if(i==4) printf("\n");
		else printf(" ");
	}
	
	
return 0;
}








