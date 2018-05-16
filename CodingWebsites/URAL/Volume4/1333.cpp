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
#define eps 1e-9
#define tn 1000000.0
using namespace std;
int dcmp(double x){return (x>-eps)-(x<eps);}
struct C{
	double x,y,r;
	bool Is(double i,double j){
		return dcmp(r-sqrt((x-i)*(x-i)+(y-j)*(y-j)))>=0;
	}
}c[10];
int N;

int main(void)
{freopen("1333.txt","r",stdin); 
	while(cin>>N){
		For(i,N) scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
		srand(N); 
		double ANS;int In=0;
		for(int i=0;i<tn;i++){
			double x=(double) rand()/RAND_MAX,y=1.0*rand()/RAND_MAX;
			int T=0;
			For(j,N) {
				if(c[j].Is(x,y)) {
					T=1;break;
				}
			}
			In+=T;
		}
		ANS=In/tn;
		printf("%.2f\n",ANS*100);
	}
return 0;
}








