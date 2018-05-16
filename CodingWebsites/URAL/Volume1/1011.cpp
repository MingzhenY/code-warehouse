#include <iostream>
#include <cstdio>
#include <cmath>
#define EPS 1e-8
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int dcmp(double a){
	return (a>-EPS)-(a<EPS);
}

int main(void)
{freopen("1011.txt","r",stdin); 
	double a,b;
	cin>>a>>b;int ANS=0;
	a+=1e-8;b-=1e-8;
	for(int i=2;i<=10000;i++){
		for(int j=1;j<i;j++){
			double k=(double)100*j/i;
			if(dcmp(k-a)>0&&dcmp(k-b)<0){
				//OUT2(dcmp(k-a),dcmp(k-b));
				//OUT3(a,k,b);
				ANS=i;break;
			}
		}
		if(ANS) break;
	}
	cout<<ANS<<endl;
	
	
	
return 0;
}








