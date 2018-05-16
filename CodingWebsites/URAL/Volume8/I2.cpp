#include <iostream>
#include <cstdio>
#include <cmath>
#define EPS 1e-9
#define  inf  1048576
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
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
struct POINT{
	double x,y;
//第一部分：构造函数 
	POINT():x(0),y(0){}
	POINT(double x,double y):x(x),y(y){}
	void Input(){
		scanf("%lf%lf",&x,&y);
	}
//第二部分：基本运算
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
	//求法向量（指向左侧),单位化 
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
	//与点相交
	bool operator *(POINT B){
		if(B==start||B==end) return 0;
		int D=dcmp((end-start).cross(B-start));
		if(D) return 0;
		if(B<Max(start,end)&&Min(start,end)<B) return 1;
		return 0; 
	}
	//线段是否相交 
	bool operator *(LINE B){ 
		if(dcmp((end-start).cross(B.end-B.start))){//如果不平行 
			POINT I=this->cross(B);
			if(I==B.start||I==B.end||I==start||I==end) return 0;
			return *this*I&&B*I;
		} 
		else {
			return *this*B.start||*this*B.end||B*start||B*end;
		}
	}
	//求线线交点 
	POINT cross(LINE B){
		int  D=dcmp((end-start).cross(B.end-B.start));
		//OUT1(D);
		if(!D) return POINT(0,0); 
		POINT C;
		C=B.start-(B.end-B.start)*((end-start).cross(B.start-start)/(end-start).cross(B.end-B.start));
		return C;
	}
};
POINT P[5];
double Dis[5][5];
double Floyd[5][5];

int main(void)
{
	freopen("I.txt","r",stdin); 
	int n;cin>>n;
	for(int t=0;t<n;t++){
		for(int i=0;i<5;i++) P[i].Input();
		//初始化邻接表
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++){
				Dis[i][j]=(P[i]-P[j]).length();
			}
		}
		//计算邻接表
		LINE L(P[0],P[1]),L1(P[2],P[3]),L2(P[3],P[4]);
		//S , T 
		if(L*L1||L*L2) Dis[0][1]=Dis[1][0]=inf;
		//S  AC
		if(LINE(P[0],P[2])*L2) Dis[0][2]=Dis[2][0]=inf;
		if(LINE(P[0],P[4])*L1) Dis[0][4]=Dis[4][0]=inf;
		//T_AC
		if(LINE(P[1],P[2])*L2) Dis[1][2]=Dis[2][1]=inf;
		if(LINE(P[1],P[4])*L1) Dis[1][4]=Dis[4][1]=inf;
		
		double D1,D2,D3,D4;
		D1=(P[0]-P[3]).polangle();
		D2=(P[1]-P[3]).polangle();
		D3=(P[4]-P[3]).polangle();
		D4=(P[2]-P[3]).polangle();
		//OUT2(D1,D2);OUT2(D3,D4);
		if(Max(D1,D2)>=Max(D3,D4)&&Min(D1,D2)<=Min(D3,D4))  ;
		else  {
			Dis[1][3]=Dis[3][1]=inf;
			if(L*P[3])  Dis[0][1]=Dis[1][0]=inf;
		}
		OUT3(Dis[0][4],Dis[4][3],Dis[3][1]);
	
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				printf("%.2f ",Dis[i][j]);
			}
			cout<<endl;
		}
		//弗洛伊德
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				Floyd[i][j]=Dis[i][j];
			}
		}
	for(int k=0;k<5;k++){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
					if(Floyd[i][k]+Floyd[k][j]<Floyd[i][j])
					Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
			}
		}
	}
		printf("%.6f\n",Floyd[1][0]);
		
	}
return 0;
}


