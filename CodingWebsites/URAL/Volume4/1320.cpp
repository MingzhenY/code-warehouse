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
int f[1001];
int n[1001];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
int main(void)
{freopen("1320.txt","r",stdin); 
	memset(n,0,sizeof(n));
	FOR(i,1000) f[i]=i;
	int a,b;int T=1;
	while(~scanf("%d%d",&a,&b)){
		int x=Find(a),y=Find(b);
		if(x!=y){
			f[x]=y;
			n[y]+=n[x];
		}
		n[y]++;
	}
	for(int i=1;i<=1000;i++){
		if(f[i]==i&&(n[i]&1)) T=0;
	}
	printf("%d\n",T);
return 0;
}








