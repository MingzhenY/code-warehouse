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
int I,K;//
bool F(int N){
	int L=0,R=N-1,M,cnt=0,Found=0;
	while(L <= R){
		M=(L+R)>>1;cnt++;
		if(M==I) {Found=1;break;}
		if(I < M) R=M-1;
		else L=M+1;
	}
	return Found&&(cnt==K);
}
bool OK[10001];
int L[10000],R[10000],N;
int main(void)
{freopen("1064.txt","r",stdin); 
	while(cin>>I>>K){
		for(int i=1;i<=10000;++i) OK[i]=F(i);
		for(int i=1;i<=10000;++i){
			if(!OK[i]) continue;
			int j=i;
			while(j<10000&&OK[j+1]) j++;
			L[N]=i;R[N]=j;N++;i=j+1;
		}
		printf("%d\n",N);
		for(int i=0;i<N;++i) printf("%d %d\n",L[i],R[i]);
	}
return 0;
}








