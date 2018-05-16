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

int N,K;
int main(void)
{freopen("1131.txt","r",stdin); 
	while(cin>>N>>K){
		int M=0;int ANS=-1;
		if(N==1) ANS=0;
		if(K==1) ANS=N-1;
		
		while((1<<M)<=K) M++;
		if(!~ANS){
			for(int i=0;i<=M;i++){
				if((1<<i)>=N) {
					ANS=i;
					break;
				}
			}	
		}
		if(!~ANS){
			ANS=(N-(1<<M)-1)/K+1+M;
		}
		cout<<ANS<<endl;
	}	
return 0;
}








