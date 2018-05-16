#include <iostream>
#include <iomanip>
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
#define eps 1e-9
int dcmp(long double x){return (x>-eps)-(x<eps);}
struct POINT{
	long double x,y,angle;
	POINT():x((long double)0.0),y((long double)0.0){}
	POINT(long double x,long double y){this->x=x;this->y=y;}
	long double length(){return sqrt(x*x+y*y);}
	POINT e(){return POINT(x/length(),y/length());}
	POINT n(){return POINT(-y/length(),x/length());}
	POINT operator +(const POINT &B)const{return POINT(x+B.x,y+B.y);}
	POINT operator -(const POINT &B)const{return POINT(x-B.x,y-B.y);}
	POINT operator *(long double k)const{return POINT(x*k,y*k);}
	POINT operator /(long double k)const{return POINT(x/k,y/k);}
	long double dot(POINT B){return x*B.x+y*B.y;}
	long double cross(POINT B){return x*B.y-y*B.x;}
}D[10000];
bool cmp(POINT A,POINT B){
	return dcmp(A.angle-B.angle)>0;
}
struct LINE{
	POINT start,end;
	LINE(){start.x=start.y=end.x=end.y=(long double)0.0;}
	LINE(POINT x,POINT y):start(x),end(y){}
	POINT cross(LINE B){
		int  D=dcmp((end-start).cross(B.end-B.start));
		if(!D) return POINT(0,0); 
		POINT C;
		C=B.start-(B.end-B.start)*((end-start).cross(B.start-start)/(end-start).cross(B.end-B.start));
		return C;
	}
};
int N;
double R;POINT O;
void F(int t){//¼ÆËãÔ²ÐÄ°ë¾¶¡£ 
	POINT A=D[0],B=D[1],C=D[t];
	if(dcmp((B-A).cross(C-A))<0){B=D[t],C=D[1];}
	POINT temp=(A+B)/(long double)2.0;
	LINE T1(temp,temp+(B-A).n());
	temp=(A+C)/(long double)2.0;
	LINE T2(temp,temp+(C-A).n());
	O=T1.cross(T2);
	R=(A-O).length();
}
int F2(int t){
	int ANS=0;
	for(int i=2;i<N;i++){
		if(i==t) continue;
		double dis=(D[i]-O ).length();
		if(dcmp(dis-R)<0) ANS++;
	} 
	return ANS;
}
int main(void)
{freopen("1103.txt","r",stdin); 
	while(cin>>N){
		For(i,N) cin>>D[i].x>>D[i].y;
		/*
		POINT LD=D[0];int LDI=0;
		for(int i=1;i<N;i++){
			if(dcmp(D[i].x-LD.x)<0||!dcmp(D[i].x-LD.x)&&dcmp(D[i].y-LD.y)<0){
				LD=D[i];LDI=i;
			}
		}
		if(LDI){
			POINT temp=D[0];
			D[0]=D[LDI];
			D[LDI]=temp;
		}*/
		for(int i=1;i<N;i++){
			D[i].angle=POINT((long double)0.0,(long double)1.0).dot(D[i]-D[0])/(D[i]-D[0]).length();
		}
		sort(D+1,D+N,cmp);
		//OUT2(D[1].x,D[1].y);
		int ANSI=-1;
		for(int i=2;i<N;i++){
			F(i);//OUT2(i,D[i].angle); 
			int DA=F2(i);
			if(DA*2+3==N){
				ANSI=i;break;
			}
		}
		cout<<setprecision(0)<<D[0].x <<" "<<D[0].y <<endl;
		cout<<setprecision(0)<<D[1].x <<" "<<D[1].y <<endl;
		if(~ANSI){
			cout<<setprecision(0)<<D[ANSI].x <<" "<<D[ANSI].y<<endl;
		}
	}
return 0;
}








