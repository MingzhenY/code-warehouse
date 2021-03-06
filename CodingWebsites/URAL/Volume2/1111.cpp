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
#define eps 1e-14
using namespace std;
int dcmp(double x){
	return (x>-eps)-(x<eps);
}
template <class T>
T Max(T a,T b){return a<b?b:a;}
template <class T>
T Min(T a,T b){return a<b?a:b;}
struct POINT{
	double x,y;
//第一部分：构造函数 
	POINT():x(0),y(0){}
	POINT(double x,double y):x(x),y(y){}
//第二部分：基本运算
	//加减 
	POINT operator +(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
	POINT operator -(const POINT &B)const{
		return POINT(x-B.x,y-B.y); 
	}
	POINT n(){
		return POINT(-y,x)*(1/this->length());
	}
	POINT e(){
		return POINT(x,y)*(1/this->length());
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
	
}S; 

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
	POINT e(){
		return (end-start).e();
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
		/*//原版 
		if(*this*B.start||*this*B.end||B*start||B*end) return 1;
		int D1=dcmp((end-start).cross(B.start-start));
		int D2=dcmp((end-start).cross(B.end-start));
		int D3=dcmp((B.end-B.start).cross(end-B.start));
		int D4=dcmp((B.end-B.start).cross(start-B.start));
		if(D1*D2<0&&D3*D4<0) return 1;
		return 0;*/
	}
	POINT cross(LINE B){
		int  D=dcmp((end-start).cross(B.end-B.start));
		//OUT1(D);
		if(!D) return POINT(0,0); 
		POINT C;
		C=B.start-(B.end-B.start)*((end-start).cross(B.start-start)/(end-start).cross(B.end-B.start));
		return C;
	}
	 double distance(POINT B){
	 	POINT C;
		if(*this*B) {return 0;}
		LINE L(B,B+(end-start).n());
		C=this->cross(L);
		if(*this*C) return (B-C).length();
		if((B-end).length()<(B-start).length()) {
			return (B-end).length();
		}
		else {
			return (B-start).length();
		}
	}
};

struct Sqare{
	LINE L,R,U,D;int index;
	double dis;
	Sqare(){}
	bool operator  <(const Sqare&X)const{
		int D=dcmp(dis-X.dis);
		if(!D) return index<X.index;
		return D <0;
	}
}sqare[50]; 
int n;int Sx,Sy;
int main(void)
{freopen("1111.txt","r",stdin); 
	while(cin>>n){
		For(i,n){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			POINT A(a,b),B,C(c,d),D;
			double Diss=(A-C).length()/2;
			B=(A+C)*0.5-(C-A).n()*Diss;
			D=(A+C)*0.5+(C-A).n()*Diss;
			
			POINT LD(a,b),LU(a,d),RD(c,b),RU(c,d);
			sqare[i].L.start=A,sqare[i].L.end=B;
			sqare[i].R.start=B,sqare[i].R.end=C;
			sqare[i].U.start=C,sqare[i].U.end=D;
			sqare[i].D.start=D,sqare[i].D.end=A;
			sqare[i].index=i;
		}
		cin>>S.x>>S.y;
		For(i,n){
			int Count=
			dcmp(sqare[i].L.e().cross(sqare[i].L.end-S))>=0+
			dcmp(sqare[i].R.e().cross(sqare[i].R.end-S))>=0+
			dcmp(sqare[i].U.e().cross(sqare[i].U.end-S))>=0+
			dcmp(sqare[i].D.e().cross(sqare[i].D.end-S))>=0;
			OUT2(i,Count);
			if(Count==4) sqare[i].dis=0.0;
			else{
				sqare[i].dis=min(min(sqare[i].L.distance(S),sqare[i].R.distance(S)),min(sqare[i].U.distance(S),sqare[i].D.distance(S)));
			}
			OUT2(i,sqare[i].dis);
		}
		sort(sqare,sqare+n);
		For(i,n){
			if(i) printf(" ");
			printf("%d",sqare[i].index+1);
		}
		cout<<endl;
	}
	
	
return 0;
}








