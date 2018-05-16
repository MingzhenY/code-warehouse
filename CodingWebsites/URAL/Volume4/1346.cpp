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

int F[100001];
int main(void)
{freopen("1346.txt","r",stdin); 
	int N,A,B,a;
	while(cin>>A>>B){
		for(int i=A;i<=B;i++) scanf("%d",&F[i]);
		int ANS=0;
		for(int i=A;i<=B;){
			int Up=1,Down=1;
			while(i+Up <=B&&F[i+Up]>=F[i+Up-1]) Up++;
			while(i+Down<=B&&F[i+Down]<=F[i+Down-1]) Down++;
			int D=max(Up,Down);
			i+=D;ANS++;
		}
		printf("%d\n",ANS);
	}
return 0;
}








