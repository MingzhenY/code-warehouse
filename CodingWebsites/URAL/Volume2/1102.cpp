/*
Memory Limit Exceeded
*/
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
char str[10000007];
int f[10000007];
int Find(int x){
	return x==f[x]?x:f[x]=Find(f[x]);
}
void Union(int x,int y){
	f[Find(x)]=Find(y);
}
bool Is(int x,int y){return Find(x)==Find(y);}
int N,n;
void F(string W,int k){
	if(k+W.length()>n) return;
	int Same=0;
	for(int i=0;i<W.length();++i) Same+=W[i]==str[k+i];
	if(Same==W.length()) Union(k+W.length(),k);
}
int main(void)
{freopen("1102.txt","r",stdin); 
	while(~scanf("%d",&N)){
		for(int i=0;i<N;++i){
			scanf("%s",str);n=strlen(str);
			for(int i=0;i<=n;++i) f[i]=i;
			for(int j=0;j<n;++j) {
				F("out",j);
				F("output",j);
				F("puton",j);
				F("in",j);
				F("input",j);
				F("one",j);
			}
			if(Is(0,n)) printf("YES\n");
			else printf("NO\n");
		}	
	}
return 0;
}








