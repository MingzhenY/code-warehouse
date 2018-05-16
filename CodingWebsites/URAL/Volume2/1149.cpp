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
void A(int n,int t){
	printf("sin(%d",t);
	if(n>1) {
		if(t&1) printf("-");
		else printf("+");
		A(n-1,t+1);
	}
	printf(")");
}
void S(int n,int t){
	
	if(n>1) {
		printf("(");
		S(n-1,t+1);
		printf(")");
	}
	A(n,1);
	printf("+%d",t); 
}
int main(void)
{freopen("1149.txt","r",stdin); 
	int N;
	while(cin>>N){
		S(N,1);
		cout<<endl;
	} 
return 0;
}








