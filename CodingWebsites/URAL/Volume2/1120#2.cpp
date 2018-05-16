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
#define eps 1e-8

int main(void)
{freopen("1120.txt","r",stdin); 
	long long N;
	while(cin>>N){
		long long A,P;int ANS=0;
		for(P=1;P*(P-1)/2<=N-P;P++){
			if((N-P*(P-1)/2)%P==0){
				ANS=P;
				A=(N-P*(P-1)/2)/P;
			}
		}
		cout<<A<<" "<<ANS<<endl;
	}
return 0;
}








