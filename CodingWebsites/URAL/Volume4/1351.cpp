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
int dcmp(double x){return (x>-eps)-(x<eps);}
struct POINT{
	int x,y;
	POINT():x(0),y(0){}
	POINT(int x,int y):x(x),y(y){}
	POINT operator -(const POINT &B)const{return POINT(x-B.x,y-B.y);}
	POINT operator +(const POINT &B)const{return POINT(x+B.x,y+B.y);}
	int length(){return x*x+y*y;}
	int operator*(const POINT &B){return x*B.x+y*B.y;}
	int cross(const POINT &B){return x*B.y-y*B.x; }
};
double Cos(POINT a,POINT b){
	//printf("\t");OUT2(a.x,a.y);OUT2(b.x,b.y);
	return a*b/sqrt(a.length())/sqrt(b.length());
}
int R;
int main(void)
{freopen("1351.txt","r",stdin); 
	while(cin>>R){
		POINT P1,P2;
		cin>>P1.x>>P1.y>>P2.x>>P2.y;
		int N;cin>>N;
		double D=Cos(P1,P2);
		For(i,N){
			POINT P;
			scanf("%d%d",&P.x,&P.y);//OUT3(i,P.x,P.y);
			if(P1.cross(P)>=0&&P.cross(P2)>=0&&R*R>=P.length()){
				if(P1.cross(P2)==0){
					if(P*P1>=0){
						printf("YES\n");
					}
					else printf("NO\n");
				}
				else{
					printf("YES\n");
				}
			}
			else printf("NO\n");
		}
	}
	
	
	
	
return 0;
}








