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

int a,b;
int countbits(int x){
	x=(x&0x55555555)+((x&0xAAAAAAAA)>>1);
	x=(x&0x33333333)+((x&0xCCCCCCCC)>>2);
	x=(x&0x0F0F0F0F)+((x&0xF0F0F0F0)>>4);
	x=(x&0x00FF00FF)+((x&0xFF00FF00)>>8);
	x=(x&0x0000FFFF)+((x&0xFFFF0000)>>16);
	return x;
}
int lowbit(int x){return x&-x;}
long long two[32];
void Init(){
	two[0]=1LL;
	for(int i=1;i<32;++i) two[i]=two[i-1]<<1;
}
long long f(int n){
	if(n<=1) return 0;
	int L=0,R=32;//[L,R)
	while(L + 1<R){
		int M=(L+R)>>1;
		if(two[M]<=n) L=M;
		else R=M;
	}
	int t=L,l=n-two[t];//n=2^t + l
	//printf("%d=2^%d + %d\n",n,t,l);
	return two[t+1]-2+f(l)-(l==0)*t; 
}
int F(int n){
	return f(n)-n+1;
}
int main(void)
{freopen("1117.txt","r",stdin); 
	Init();
	while(~scanf("%d%d",&a,&b)){
		if(a>b){a=a^b;b=a^b;a=a^b;}
		printf("%d\n",F(b)-F(a));
	}
return 0;
}








