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
#define LL long long
using namespace std;

int N,K;
int L[10000]; 
int Read(){
	int a,b;
	scanf("%d%*c%d",&a,&b);
	return a*100+b;
}
bool F(int k){
	LL Cnt=0;
	for(int i=0;i<N;++i) Cnt+=L[i]/k;
	return Cnt>=K;
}
int main(void)
{freopen("1184.txt","r",stdin); 
	while(cin>>N>>K){
		for(int i=0;i<N;++i) L[i]=Read();
		int L=1,R=10000001;//[L,R)
		while(L+1<R){
			int M=(L+R)>>1;
			if(F(M)) L=M;
			else R=M;
		}
		if(F(L)) printf("%d.%02d\n",L/100,L%100);
		else printf("0.00\n");
	}
return 0;
}








