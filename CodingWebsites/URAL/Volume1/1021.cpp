#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define D 32768
using namespace std;

int Na,Nb;
int a[50000];
int b[50000]; 
int zrt[65536];
int main(void)
{freopen("1021.txt","r",stdin); 
	memset(zrt,0,sizeof(zrt));
	cin>>Na;
	For(i,Na) scanf("%d",&a[i]),zrt[D+a[i]]=1;
	cin>>Nb;int T=0;
	For(i,Nb) {
		scanf("%d",&b[i]);
		if(10000-b[i]>32767) continue;
		if(zrt[D+10000-b[i]]) T=1;
	}
	if(T) cout<<"YES\n";
	else cout<<"NO\n";
return 0;
}








