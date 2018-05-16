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
#define eps 1e-9
int dcmp(double x){return (x>-eps)-(x<eps);}
int N,M;
int main(void)
{freopen("1113.txt","r",stdin); 
	while(cin>>N>>M){
		double K=(double)N/M;
		double D=0.0;int i;
		for(i=1;;i++){
			D+=1.0/(2*i-1);
			if(dcmp(D-K)>0) break;
		}
		D-=1.0/(2*i-1);i--;
		
		double ANS=i;
		ANS+=(K-D)*(2*i+1);
		ANS*=M;
		printf("%.0f\n",ceil(ANS));
	}
return 0;
}








