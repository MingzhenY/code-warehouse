#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct Node{
	int v;
	int sod;
	void Init(){
		sod=0;int x=v;
		while(x) sod+=x%10,x/=10;
	}
	bool operator <(const Node &B)const{return sod<B.sod||sod==B.sod&&v<B.v;}
}A[1000000]; 
int N;
int main(void)
{freopen("2052.txt","r",stdin); 
	while(~scanf("%d",&N)){
		for(int i=1;i<=N;++i){
			A[i].v=i;
			A[i].Init();
		}
		sort(A+1,A+N+1);
		int ANS=0;
		for(int i=1;i<=N;++i){
			ANS+=A[i].v==i;
			//OUT2(i,A[i].v);
		}
		printf("%d\n",ANS);
	}
return 0;
}








