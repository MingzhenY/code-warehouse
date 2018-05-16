#include <iostream>
#include <cstdio>
#include <cmath>

#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct POINT{
	double x,y;
	POINT(double x,double y):x(x),y(y){}
	POINT(){}
	POINT operator+(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
	POINT operator-(const POINT &B)const{
		return POINT(x-B.x,y-B.y);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
	
};
struct LINE{
	POINT start,end;
	LINE(POINT a,POINT b):start(a),end(b){}
	LINE(){}
	double length(){
		return (start-end).length();
	}
};
int N;double R;
LINE L[100];
int main(void)
{freopen("1020.txt","r",stdin); 
	cin>>N>>R;
	For(i,N){
		scanf("%lf%lf",&L[i].start.x,&L[i].start.y);
	}
	For(i,N){
		L[i].end=L[(i+1)%N].start;
	}
	double ANS=0;
	For(i,N){
		ANS+=L[i].length();
	}
	ANS+=2*acos(-1)*R;
	printf("%.2f\n",ANS);
return 0;
}








