#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double C(int n,int m){
	double ANS=1.0;
	for(int i=2;i<=n;++i) ANS*=i;
	for(int i=2;i<=m;++i) ANS/=i;
	for(int i=2;i<=n-m;++i) ANS/=i;
	return ANS;
}
int main(void)
{
	freopen("476B.txt","r",stdin); 
	string a,b;
	while(cin>>a>>b){
		int Da=0;for(int i=0;i<a.length();++i) Da+=a[i]=='+'?1:-1;
		int Db=0,Q=0;
		for(int i=0;i<b.length();++i){
			if(b[i]=='?') ++Q;
			else Db+=b[i]=='+'?1:-1;
		} 
		int D=Da-Db;
		if((D+Q)&1){
			printf("%.12f\n",0);
			continue;
		}
		else{
			D=D>0?D:-D;Q=Q>0?Q:-Q;
			if(D>Q){
				printf("%.12f\n",0);
				continue;
			}
			
			double ANS=C(Q,(D+Q)>>1)/pow(2,Q);
			printf("%.12f\n",ANS);
		}
	}

		
return 0;
}














