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

int pow2[31];
void init(){
	pow2[0]=1;
	for(int i=1;i<31;++i) pow2[i]=pow2[i-1]<<1;
} 
int D[31];
int N,ERR,ANS;
void F(int k,int from,int to,int via){
	if(ERR) return;
	if(D[k]==via) {ERR=1;return;}
	if(D[k]==from) if(k>0) F(k-1,from,via,to);
	if(D[k]==to){
		ANS+=pow2[k];
		if(k>0) F(k-1,via,to,from);
	}
}
int main(void)
{freopen("1054.txt","r",stdin); 
	init();
	while(cin>>N){
		for(int i=0;i<N;++i) scanf("%d",&D[i]);
		ANS=ERR=0;
		F(N-1,1,2,3);
		if(ERR) ANS=-1;
		cout<<ANS<<endl;
	}
return 0;
}








