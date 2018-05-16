#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-9
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int dcmp(double a){
	return (a>-eps)-(a<eps);
}
struct POINT{
	double x,y;
	POINT(){}
	POINT(double x,double y):x(x),y(y){}
	double length(){
		return sqrt(x*x+y*y);
	}
	double cross(POINT &B){
		return x*B.y-y*B.x;
	}
	POINT operator -(const POINT &B)const{
		return POINT(x-B.x,y-B.y);
	}
	POINT operator +(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
};
int F[100001];
int N;
int main(void)
{freopen("1010.txt","r",stdin); 
	//ÊäÈë 
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",&F[i]);
	}
	//¼ÆËã
	double ANS=0;int ANSI=0;
	for(int i=1;i<N;i++){
		double D=((double)F[i+1]-F[i]);
		D=D>0?D:-D;
		if(D>ANS){
			ANSI=i;
			ANS=D;
		}
	}
	//Êä³ö 
	printf("%d %d\n",ANSI,ANSI+1);
	
	
return 0;
}








