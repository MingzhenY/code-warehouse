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
#define LL long long
using namespace std;

LL Count(LL x){
	LL k=0;
	while(x){
		k++;
		x/=10;
	}
	return k;
}
LL  A[10],ten[10];
void F(LL x,LL n){
	if(n==0) return;
	LL k=x/ten[n-1],r=x-k*ten[n-1];
	for(int i=0;i<10;++i) A[i]+=k*(n-1)*(ten[n-1]/10);
	for(int i=0;i<k;++i) A[i]+=ten[n-1];
	A[k]+=r;
	F(r,n-1); 
}
int main(void)
{freopen("1150.txt","r",stdin); 
	ten[0]=1;LL x;
	for(int i=1;i<10;++i) ten[i]=10*ten[i-1];
	while(cin>>x){
		++x;
		memset(A,0,sizeof(A));
		F(x,Count(x));
		A[0]-=(ten[Count(x)-1]*10-1)/9;
		for(int i=0;i<10;++i) cout<<A[i]<<endl;
	}
return 0;
}








