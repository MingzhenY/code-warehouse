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

long long Ans[2000001];
int last[2000001];
int n;
long long F(int n){
	if(Ans[n]) return Ans[n];
	long long ANS=1;
	for(int i=2;i<=n;i++){
		long long D=F(n/i+n%i);
		if(D*i>ANS){
			ANS=D*i;
			last[n]=i;
		}
	}
	return Ans[n]=ANS;
}
int main(void)
{freopen("1324.txt","r",stdin); 
	memset(Ans,0,sizeof(Ans));
	for(int i=1;i<=2000000;++i) last[i]=i;
	Ans[1]=1;
	while(cin>>n){
		//F(n);
		OUT2(n,F(n));
		int t=n,ALL=0;
		while(1){
			ALL++;
			t=last[t];
			if(t==last[t]) break;
		}
		t=n;printf("%d\n",ALL);
		while(1){
			printf("%d\n",last[t]);
			t=last[t];
			if(t==last[t]) break;
		}
	}
return 0;
}








