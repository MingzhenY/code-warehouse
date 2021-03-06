#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int L[5],R[5];
double F(int i,int k){
	if(k <=L[i]) return 0;
	if(k > R[i]) return 1;
	return (double)(k-L[i])/(R[i]-L[i]+1);
}
double S(int k){
	double ANS=1.0;
	for(int i=0;i<n;++i) ANS*=F(i,k);
	return ANS;
}
double T(int k){
	double ANS=0;
	for(int i=0;i<n;++i){
		double D=1.0;
		for(int j=0;j<n;++j){
			if(j!=i) D*=F(j,k);
		}
		ANS+=D;
	}
	return ANS;
}
int main(void)
{
	freopen("513C.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<n;++i) scanf("%d%d",&L[i],&R[i]);
		double ANS,D1=0,D2=0;
		for(int i=2;i<=10000;++i){D1+=S(i);D2+=T(i); }
		ANS=10000+(n-1)*D1-D2;
		printf("%.10f\n",ANS);
	}
return 0;
}














