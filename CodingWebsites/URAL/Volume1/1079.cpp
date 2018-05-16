#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N;
int a[100000];
int b[100000];
int f(int i);
int main(void)
{freopen("1079.txt","r",stdin); 
	memset(a,-1,sizeof(a));memset(b,0,sizeof(b));
	int Max=0;
	For(i,100000) {
		if(f(i)>Max) Max=f(i);
		b[i]=Max;
		//if(i<100) OUT3(i,a[i],b[i]);
	}
	
	while(cin>>N&&N){
		cout<<b[N]<<endl;
	}
return 0;
}
int f(int i){
	if(~a[i]) return a[i];
	if(i<2) return a[i]=i;  
	if(i&1){
		return a[i]=f(i/2)+f(i/2+1);
	}
	else{
		return a[i]=f(i>>1);
	}
}







