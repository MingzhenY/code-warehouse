#include <iostream>
#include <cstdio>
#include <cmath>

#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
#define eps 1e-9

int dcmp(double a){
	return (a>-eps)-(a<eps);
}

double g=9.81;
double l,h,w; 
double F(double r){
	return g*r*r*M_PI*M_PI/2/w/w+l/2*abs(sin(r*M_PI));
}
int main(void)
{
	freopen("1800.txt","r",stdin); //距离函数不单调，没法二分…… 
	while(cin>>l>>h>>w){
		h/=100;l/=100;
		w=w/60*2*M_PI;
		int D;
		for(int i=0;;i++){
			if(F(i+0.5)>h) {
				D=i;break;
			}
		}
		//int D=(int)(w*M/M_PI+0.5);
		//OUT3(M,F(M),w*M/M_PI);
		if(D&1) printf("bread\n");
		else printf("butter\n");
	}
return 0;
}














