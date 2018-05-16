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
using namespace std;
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
//��һ���֣����캯�� 
	POINT():x(0),y(0){}
	POINT(double x,double y):x(x),y(y){}
//�ڶ����֣���������
	//�Ӽ� 
	POINT operator +(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
	POINT operator -(const POINT &B)const{
		return POINT(x-B.x,y-B.y); 
	}
	//��������ָ�����),��λ�� 
	POINT LeftNV(){
		return POINT(-y,x)*(1/this->length());
	}
	POINT e(){
		return POINT(x,y)*(1/this->length());
	}
	//ȡģ���󽻽�,���� 
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
	//��ˣ���� ,���� 
	double operator *(const POINT &B)const{
		return x*B.x+y*B.y;
	}
	double cross(const POINT B){
		return x*B.y-y*B.x;
	}
	POINT operator *(const double k)const{
		return POINT(k*x,k*y);
	}
	//�ȽϺ���
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
	//���� 
	LINE(){start.x=start.y=end.x=end.y=0;}
	LINE(POINT a,POINT b):start(a),end(b){}
	//���ȣ����� 
	double length(){
		return (end-start).length();
	}
	double polangle(){
		return (end-start).polangle();
	}
	//����ཻ
	bool operator *(POINT B){
		if(B==start||B==end) return 1;
		int D=dcmp((end-start).cross(B-start));
		if(D) return 0;
		if(B<Max(start,end)&&Min(start,end)<B) return 1;
		return 0; 
	}
	//�߶��Ƿ��ཻ 
	bool operator *(LINE B){ 
		if(dcmp((end-start).cross(B.end-B.start))){//�����ƽ�� 
			POINT I=this->cross(B);
			return *this*I&&B*I;
		} 
		else {
			return *this*B.start||*this*B.end||B*start||B*end;
		}
		/*//ԭ�� 
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
		if(*this*B) return 0;
		LINE L(B,B+(end-start).LeftNV());
		POINT C=this->cross(L);
		if(*this*C) return (B-C).length();
		if((B-end).length()<(B-start).length()) {
			return (B-end).length();
		}
		else {
			return (B-start).length();
		}
	}
};
LINE L[100];int N;int a,b;
int main(void)
{freopen("1215.txt","r",stdin); 
	while(cin>>a>>b>>N){
		For(i,N){
			scanf("%lf%lf",&L[i].start.x,&L[i].start.y);
		}
		For(i,N){
			L[i].end=L[(i+1)%N].start;
		}
		POINT A(a,b);
		int T=0;
		For(i,N){
			if((L[i].end-L[i].start).cross(A-L[i].start)>=0) T++;
		}
		double ANS=L[0].distance(A);
		for(int i=1;i<N;i++){
			double D=L[i].distance(A);
			if(D <ANS)ANS=D;
		}
		if(T==N) ANS=0;
		printf("%.3f\n",2*ANS);
	}
	
return 0;
}








