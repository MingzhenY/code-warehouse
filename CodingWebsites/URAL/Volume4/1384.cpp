#include<cstdio>
#include<cstdlib>
#include<cmath>
#include <queue>
#include<iostream>
#include <algorithm>
#include<cstring>
#define EPS 1e-9 
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std; 
template <class T>
T Max(T a,T b){return a<b?b:a;}
template <class T>
T Min(T a,T b){return a<b?a:b;}
int dcmp(double a){
	return (a>-EPS)-(a<EPS);
}
struct POINTZ{
	double x,y;

	POINTZ():x(0),y(0){}
	POINTZ(double x,double y):x(x),y(y){}

	POINTZ operator +(const POINTZ &B)const{
		return POINTZ(x+B.x,y+B.y);
	}
	POINTZ operator -(const POINTZ &B)const{
		return POINTZ(x-B.x,y-B.y); 
	}
	//
	double length(){
		return sqrt(x*x+y*y);
	} 
	double angle(POINTZ B){
		return acos(*this*B/this->length()/B.length());
	}
	//
	POINTZ LeftNV(){
		return POINTZ(-y,x)*(1/this->length());
	}
	POINTZ e(){
		return POINTZ(x,y)*(1/this->length());
	}
	//
	double operator *(const POINTZ &B)const{
		return x*B.x+y*B.y;
	}
	double cross(const POINTZ B){
		return x*B.y-y*B.x;
	}
	POINTZ operator *(const double k)const{
		return POINTZ(k*x,k*y);
	}
	//
	bool operator <(const POINTZ &B)const{
		return dcmp(x-B.x)==-1||dcmp(x-B.x)==0&&dcmp(y-B.y)==-1;
	}
	bool operator ==(const POINTZ &B)const{
		return dcmp(x-B.x)==0&&dcmp(y-B.y)==0;
	}
	bool operator <=(const POINTZ &B)const{
		return *this<B||*this==B; 
	}
	
}; 

struct LINE{
	POINTZ start,end;
	//
	LINE(){start.x=start.y=end.x=end.y=0;}
	LINE(POINTZ a,POINTZ b):start(a),end(b){}
	//
	double length(){
		return (end-start).length();
	}
	//
	bool operator *(POINTZ B){
		if(B==start||B==end) return 1;
		int D=dcmp((end-start).cross(B-start));
		if(D) return 0;
		if(B<Max(start,end)&&Min(start,end)<B) return 1;
		return 0; 
	}
	//
	bool operator *(LINE B){ 
		if(dcmp((end-start).cross(B.end-B.start))){//
			POINTZ I=this->cross(B);
			return *this*I&&B*I;
		} 
		else {
			return *this*B.start||*this*B.end||B*start||B*end;
		}
	}
	//
	POINTZ cross(LINE B){
		int  D=dcmp((end-start).cross(B.end-B.start));
		//OUT1(D);
		if(!D) return POINTZ(0,0); 
		POINTZ C;
		C=B.start-(B.end-B.start)*((end-start).cross(B.start-start)/(end-start).cross(B.end-B.start));
		return C;
	}
	//
	double distance(POINTZ B,POINTZ &C){
		if(*this*B) {C=B;return 0;}
		LINE L(B,B+(end-start).LeftNV());
		C=this->cross(L);
		if(*this*C) return (B-C).length();
		if((B-end).length()<(B-start).length()) {
			C=end;return (B-end).length();
		}
		else {
			C=start;return (B-start).length();
		}
	}
	
};
struct Edge{
	LINE L;POINTZ N;
};
Edge E[30];
double ANSD[60];
POINTZ ANSN[60];
int N;
POINTZ Cir(POINTZ O,double &Doub);
double minCir(POINTZ);
int main(void)
{
	freopen("1384.txt","r",stdin);
	while(cin>>N){
	
	
		//
		for(int i=0;i<N;i++){
			scanf("%lf%lf",&E[i].L.start.x,&E[i].L.start.y);
			if(i) E[i-1].L.end=E[i].L.start;
		}
		E[N-1].L.end=E[0].L.start;
		
		//
		for(int i=0;i<N;i++){
			if(i&1) continue;
			//ANSN[i]=Cir((E[i].L.start+E[i].L.end)*0.5+(E[i].L.end-E[i].L.start).LeftNV()*0.01);
			//ANSD[i]=minCir(ANSN[i]);
			
			POINTZ a, b;
			a = E[i].L.start - E[i].L.end; b = E[(i + 1) % N].L.end - E[(i + 1) % N].L.start;
			int D = dcmp(b.cross(a));
			if (D){
				ANSN[N + i] = Cir(E[i].L.end+(a+b).e()*(D*0.5),ANSD[N+i]);
				//ANSD[N + i] = minCir(ANSN[N+i]);
			}
			else ANSD[N+i]=0;
		}
		double ANS=ANSD[0];POINTZ ANSP=ANSN[0];
		for(int i=N;i<2*N;i++) if(ANSD[i]>ANS) ANS=ANSD[i],ANSP=ANSN[i];
		printf("%.2f\n",ANS);
	}
	         
    return 0;
}
double minCir(POINTZ O){
	POINTZ temp;double D;
	double ANS=1<<30;
	for(int i=0;i<N;i++){
		D=E[i].L.distance(O,temp);
		if(D < ANS) ANS=D;
	}
	return ANS;
}

POINTZ Cir(POINTZ O,double &Doub){
	double D[30];
	start:
	for(int i=0;i<N;i++){
		D[i]=E[i].L.distance(O,E[i].N);
	}
	double ANS1=1<<30,ANS2=1<<30;int I1=0,I2=0;
	for(int i=0;i<N;i++){
		if(D[i]<ANS1) {
			ANS1=D[i];I1=i;
		}
	}
	for(int i=0;i<N;i++){
		if(i==I1) continue;
		if(E[i].N==E[I1].N) continue;
		if(D[i]<ANS2) {
			ANS2=D[i];I2=i;
		}
	}
	POINTZ A=E[I1].N,B=E[I2].N;
	POINTZ C;LINE L(A,B);
	if(L.start==O||dcmp((L.end-L.start).cross(O-L.start))==0){
		C=A;
	}
	else{
		//LINE L2(O,O+(A-O)*(1/(A-O).length())+(B-O)*(1/(B-O).length()));
		//C=L.cross(L2);
		C=A+(B-A)*(ANS1/(ANS1+ANS2));
	//	C.x=A.x+(B.x-A.x)*(ANS1/(ANS1+ANS2));
	//	C.y=A.y+(B.x-A.x)*(ANS1/(ANS1+ANS2));
	}
	
	double k=1.5;
	double ND;
	do{
		//printf("%f\n",k);
		k/=2;
		ND=minCir(O+(O-C).e()*k);
		if(k<1e-2) {
			Doub=ND;
			return O+(O-C).e()*k;
		}
	}while(ND<ANS1);
	O=O+(O-C).e()*k;
	goto start;
}
