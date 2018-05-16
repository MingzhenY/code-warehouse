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
int f[10001];
int Find(int i){
	return i==f[i]?i:Find(f[i]);
}
int Union(int i,int j){
	return f[Find(i)]=Find(j);
}
int Is(int i,int j){
	return Find(i)==Find(j);
}
int N,K,M;
int main(void)
{freopen("1272.txt","r",stdin); 
	int a,b;
	while(cin>>N>>K>>M){
		FOR(i,N) f[i]=i;
		For(i,K){
			scanf("%d%d",&a,&b);
			if(Is(a,b)) continue;
			Union(a,b);
		} 
		int ANS=0;
		For(i,M){
			scanf("%d%d",&a,&b);
			if(Is(a,b)) continue;
			ANS++;Union(a,b);
		}
		cout<<ANS<<endl;
	}
return 0;
}








