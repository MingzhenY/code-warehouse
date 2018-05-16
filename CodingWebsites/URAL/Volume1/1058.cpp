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
#define Angles 1000
using namespace std;
const double delta=acos(-1)/Angles;
int sgn(double x){return (x > -eps)-(x < eps);}
struct P{
	double x,y;
	P():x(0.0),y(0.0){}
	P(double x,double y):x(x),y(y){}
	P operator +(const P B)const{return P(x+B.x,y+B.y);}
	P operator -(const P B)const{return P(x-B.x,y-B.y);}
	double operator *(const P B){return x*B.x+y*B.y;}
	P operator /(const double k){return P(x/k,y/k);}
	P operator *(const double k){return P(x*k,y*k);}
	P rotate(double t){return P(x*cos(t)-y*sin(t),y*cos(t)+x*sin(t));}
	bool operator <(const P &B)const{return sgn(x-B.x)<0 || sgn(x-B.x)==0 && sgn(y-B.y)<0;}
	double len(){return sqrt(x*x+y*y);}
	bool operator ==(const P &B)const{return !sgn(x-B.x)&&!sgn(y-B.y);}
}D[51];
int N;double Area;//Area为总面积 
double TriArea(double a,double b,double c){
	double t=(a+b+c)/2;
	return sqrt(t*(t-a)*(t-b)*(t-c));
} 
void Step_0(){//Rotate
	for(int i=0;i<N;++i) D[i]=D[i].rotate(delta);
}
void Step_1(){//使D[1]为最左下角的点. 
	P D2[51];
	P LD_most=D[0];int ID=0;
	for(int i=0;i<N;++i){
		D2[i]=D[i];
		if(D[i]<LD_most){
			LD_most=D[i];
			ID=i;
		}
	} 
	for(int i=0;i<N;++i) D[i]=D2[(ID+i)%N];
}
void Step_2(double X,P &Up,P &Down){//根据横坐标X算出俩交点 Up,Down;
	for(int i=0;i<N;++i){
		P d1=D[i],d2=D[(i+1)%N];
		if(sgn(d1.x-X)<=0 && sgn(d2.x-X)>0){
			Down=d1+(d2-d1)*((X-d1.x)/(d2.x-d1.x));
		}
		if(sgn(d1.x-X)>=0 && sgn(d2.x-X)<0){
			Up=d1+(d2-d1)*((X-d1.x)/(d2.x-d1.x));
		}
	}
} 
bool Step_3(double X){//根据横坐标X判断左边面积是否大于右边 
	P D2[51],Up,Down;int D2n=0;
	Step_2(X,Up,Down);
	D2[D2n++]=Down;
	for(int i=0;i<N;++i){
		if(sgn(D[i].x-X)>0){
			D2[D2n++]=D[i];
		}
	}
	D2[D2n]=Up;
	double R_Area=0.0;
	for(int i=0;i<D2n;++i) R_Area+=TriArea(D2[i].len(),D2[i+1].len(),(D2[i+1]-D2[i]).len());
	R_Area-=sgn(X)*TriArea(D2[0].len(),D2[D2n].len(),(D2[0]-D2[D2n]).len());
	return sgn(Area-2*R_Area)<=0;
}
double BinarySearch(){//计算当前方向的最小割线长度 
	Step_1();//更新坐标顺序 
	double L=D[0].x,R=D[0].x;//求二分范围 
	for(int i=1;i<N;++i) {
		L=min(L,D[i].x);
		R=max(R,D[i].x);
	}
	//开始二分
	while(R-L>1e-5){
		double M=(L+R)/2;
		if(Step_3(M)) L=M;
		else R=M;
	} 
	P Up,Down;
	Step_2(L,Up,Down);
	return (Up-Down).len();
}
int main(void)
{freopen("1058.txt","r",stdin);
	while(cin>>N){
		D[N].x=D[N].y=0.0;
		for(int i=0;i<N;++i) {
			scanf("%lf%lf",&D[i].x,&D[i].y);
			D[N]=D[N]+D[i];
		}
		D[N]=D[N]/(double) N;
		for(int i=0;i<N;++i) D[i]=D[i]-D[N];
		
		//计算总面积
		Area=0.0; 
		for(int i=0;i<N;++i){
			P A=D[i],B=D[(i+1)%N];
			Area+=TriArea(A.len(),B.len(),(A-B).len());
		}
		//原点为重心
		double ANS=1e9;
		for(int i=0;i<Angles;++i){
			double tANS=BinarySearch();
			ANS=min(ANS,tANS);
			Step_0();
		}
		printf("%.4f\n",ANS);
	}
return 0;
}








