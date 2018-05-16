//空间的两点A,B，求不经过某球形空间的最短路径距离 
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
using namespace std;
int sgn(double x){return (x>-eps)-(x<eps);}
struct P{
	double x,y,z;
	P(){x=y=z=0.0;}
	P(double x,double y,double z):x(x),y(y),z(z){}
	void Input(){cin>>x>>y>>z;}
	P operator +(const P B)const{return P(x+B.x,y+B.y,z+B.z);}
	P operator -(const P B)const{return P(x-B.x,y-B.y,z-B.z);}
	double operator *(const P B)const{return x*B.x+y*B.y+z*B.z;}
	P operator *(const double k)const{return P(x*k,y*k,z*k);}
	P operator /(const double k)const{return P(x/k,y/k,z/k);}
	double len(){return sqrt(x*x+y*y+z*z);}
	double sqlen(){return x*x+y*y+z*z;}
};
P Func(P A,P B,bool &t){
	double k1,k2;
	k1=(B.sqlen()-A*B)/(A-B).sqlen();
	k2=(A.sqlen()-A*B)/(A-B).sqlen();
	t=sgn(k1)>=0&&sgn(k2)>=0;
	return A*k1+B*k2;
}
double angle(P A,P B){
	return A*B/A.len()/B.len();
}
P A,B,C;
double R;
int main(void)
{freopen("1075.txt","r",stdin); 
	A.Input();B.Input();C.Input();cin>>R;
	bool In;
	P D=Func(A-C,B-C,In);
	double d=D.len(),D1=(A-C).len(),D2=(B-C).len();
	double ANS;
	if(d <= R&&In){
		double t0,t1,t2,t;
		t0=acos(angle(A-C,B-C));
		t1=acos(R/D1);
		t2=acos(R/D2);
		t=t0-t1-t2;
		ANS=sqrt(D1*D1-R*R)+sqrt(D2*D2-R*R)+t*R; 
	}
	else ANS=(A-B).len();
	printf("%.2f\n",ANS);
return 0;
}








