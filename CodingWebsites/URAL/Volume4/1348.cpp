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
#define EPS 1e-9
template <class T>
T Max(T a,T b){return a<b?b:a;}
template <class T>
T Min(T a,T b){return a<b?a:b;}
int dcmp(double a){
	return (a>-EPS)-(a<EPS);
}
struct POINT{
	double x,y;
	POINT():x(0),y(0){}
	POINT(double x,double y):x(x),y(y){}
	//加减 
	POINT operator +(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
	POINT operator -(const POINT &B)const{
		return POINT(x-B.x,y-B.y); 
	}
	//取模，求交角,极角 
	double length(){
		return sqrt(*this**this);
	} 
	double angle(POINT B){
		return acos(*this*B/this->length()/B.length());
	}
	double polangle(){
		int D=-dcmp(this->cross(POINT(1,0)));
		return 2*M_PI*(!~D)+!D*M_PI*(dcmp(this->x)==-1)+D*this->angle(POINT(1,0));
	}
	POINT n(){
		return POINT(-y,x)*(1/this->length());
	}
	POINT e(){
		return POINT(x,y)*(1/this->length());
	}
	//点乘，叉乘 ,数乘 
	double operator *(const POINT &B)const{
		return x*B.x+y*B.y;
	}
	double cross(const POINT B){
		return x*B.y-y*B.x;
	}
	POINT operator *(const double k)const{
		return POINT(k*x,k*y);
	}
	//比较函数
	bool operator <(const POINT &B)const{
		return dcmp(x-B.x)==-1||dcmp(x-B.x)==0&&dcmp(y-B.y)==-1;
	}
	bool operator ==(const POINT &B)const{
		return dcmp(x-B.x)==0&&dcmp(y-B.y)==0;
	}
	bool operator <=(const POINT &B)const{
		return *this<B||*this==B; 
	}
	
}; 
struct LINE{
	POINT start,end;
	//构造 
	LINE(){start.x=start.y=end.x=end.y=0;}
	LINE(POINT a,POINT b):start(a),end(b){}
	//长度，极角 
	double length(){
		return (end-start).length();
	}
	double polangle(){
		return (end-start).polangle();
	}
	//与点相交
	bool operator *(POINT B){
		if(B==start||B==end) return 1;
		int D=dcmp((end-start).cross(B-start));
		if(D) return 0;
		if(B<Max(start,end)&&Min(start,end)<B) return 1;
		return 0; 
	}
	//线段是否相交 
	bool operator *(LINE B){ 
		if(dcmp((end-start).cross(B.end-B.start))){//如果不平行 
			POINT I=this->cross(B);
			return *this*I&&B*I;
		} 
		else {
			return *this*B.start||*this*B.end||B*start||B*end;
		}
	}
	POINT cross(LINE B){
		int  D=dcmp((end-start).cross(B.end-B.start));
		//OUT1(D);
		if(!D) return POINT(0,0); 
		POINT C;
		C=B.start-(B.end-B.start)*((end-start).cross(B.start-start)/(end-start).cross(B.end-B.start));
		return C;
	}
};

int main(void)
{freopen("1348.txt","r",stdin); 
	POINT A,B,C;double L;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&L)){
		LINE L1(A,B),L2(C,C+(A-B).n());
		POINT X=L1.cross(L2);
		POINT Near,Far;
		if((B-C).length()<(A-C).length()){Near=B;Far=A;}
		else {Near=A;Far=B;}
		if(L1*X&&(X-C).length()<(Near-C).length()) Near=X; 
		double ANS1,ANS2;
		ANS1=(Near-C).length();
		ANS2=(Far-C).length();
		if(ANS1>=L) ANS1-=L;
		else ANS1=0.0;
		if(ANS2>=L) ANS2-=L;
		else ANS2=0.0;
		printf("%.2f\n%.2f\n",ANS1,ANS2);
	}
return 0;
}








