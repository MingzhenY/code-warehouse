#include <iostream>
#include <cstdio>
#include <cmath>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
long long max(long long a,long long b) {return a>b?a:b;}
long long min(long long a,long long b) {return a<b?a:b;}


long long F(long long x);
long long SF(long long x);
long long E[20];


int main(void)
{
	freopen("C.txt","r",stdin); 
	long long N;
	E[1]=1;
	for(int i=2;i<20;i++) E[i]=10*E[i-1]+1;
	scanf("%I64d",&N);
	cout<<SF(N)<<endl;
return 0;
}
long long F(long long x){
	if(x<0) x=-x;
	if(x==0) return 0;
	if(x<=6) return x;
	if(x<=11) return 13-x;
	int MaxL;
	while(x>=E[MaxL]){
		if(x==E[MaxL]) return MaxL;
		MaxL++;
	}
	MaxL--; 
	long long k=x/E[MaxL];
	if(x%E[MaxL]==0) return k*MaxL;
	return min(k*MaxL+F(x-k*E[MaxL]),(k+1)*MaxL+F((k+1)*E[MaxL]-x) ); 
	
}
long long SF(long long x){
	if(x<0) x=-x;
	if(x<=11) return F(x);
	int MaxL;
	while(x>=E[MaxL]){
		if(x==E[MaxL]) return MaxL;
		MaxL++;
	}
	return min(F(x),F(E[MaxL]-x)+MaxL);
}













