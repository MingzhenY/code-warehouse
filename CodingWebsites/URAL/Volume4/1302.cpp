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

int m,n;
int mx,my,nx,ny;
void F(int k,int &x,int &y){
	double D=ceil(sqrt((double)k))-1;
	x=D;y=k-x*x-x-1;
} 
int main(void)
{freopen("1302.txt","r",stdin); 
	while(cin>>m>>n){
		if(m>n) {int t=m;m=n;n=t;}
		F(m,mx,my);F(n,nx,ny);
		int ANS=0; 
		while(mx < nx){//先走到同一层。 
			int D=2*(my <=ny)-1;
			if((mx^m)&1){mx++;}
			else my+=D;
			m=mx*mx+mx+1+my;
			ANS++;
		}
		ANS+=abs(my-ny);
		printf("%d\n",ANS);
	}
return 0;
}








