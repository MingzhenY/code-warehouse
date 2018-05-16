#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#define EPS 1e-9
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
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
//第二部分：基本运算
	//加减 
	POINT operator +(const POINT &B)const{
		return POINT(x+B.x,y+B.y);
	}
	POINT operator -(const POINT &B)const{
		return POINT(x-B.x,y-B.y); 
	}	
	//点乘，叉乘 ,数乘
	double cross(const POINT B){
		return x*B.y-y*B.x;
	}
}; 
POINT p[200];int N;
int main(void)
{freopen("1052.txt","r",stdin); 
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>p[i].x>>p[i].y;
	}
	int ANS=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int count=0;
			for(int k=0;k<N;k++){
				if(k==i||k==j) continue;
				if(!dcmp((p[j]-p[i]).cross(p[k]-p[i]))) count++;
			}
			if(ANS<count+2){
				ANS=count+2;
			}
		}
	}
	cout<<ANS<<endl;
	
	
return 0;
}








