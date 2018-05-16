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

int N,M,Y;
int F(int x){
	int ANS=x%M;
	For(i,N-1){
		ANS*=x;
		ANS%=M;
	}
	return ANS;
}
int main(void)
{freopen("1110.txt","r",stdin); 
	while(cin>>N>>M>>Y){
		int T=1;
		For(i,M){
			if(F(i)==Y) {
				if(T) printf("%d",i),T=0;
				else printf(" %d",i);
			}
		}
		if(T) cout<<"-1";
		cout<<endl;
	}
return 0;
}








