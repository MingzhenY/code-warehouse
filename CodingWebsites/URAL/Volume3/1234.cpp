#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-9
int dcmp(double a){
	return (a>-eps)-(a<eps);
}
double D,E;
void swap(double &a,double &b){
	if(a>b){
		double  t=a;
		a=b;
		b=t;
	}
}
bool F(double A,double B){
	if(dcmp(A-D)>0&&dcmp(B-D)>0) return 0;
	if(dcmp(A-D)<=0&&dcmp(B-D)<=0) return 1;
	swap(A,B);
	double t=(B-sqrt(A*A+B*B-D*D))/(A+D);
	double D1=(B*(B+E)-A*(A+D))*t;
	double D2=B*D-A*E;
	return dcmp(D1-D2)>=0;
}
int main(void)
{freopen("1234.txt","r",stdin); 
	double A,B,C;
	while(cin>>A>>B>>C>>D>>E){
		swap(D,E);
		int T;
		T=F(A,B)||F(B,C)||F(A,C);
		if(T) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
return 0;
}








