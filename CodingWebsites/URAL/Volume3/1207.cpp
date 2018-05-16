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
struct Point{
	long long x,y;
	int i;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	double length(){
		return sqrt((double) x*x+y*y);
	}
	Point operator -(const Point&B)const{
		return Point(x-B.x,y-B.y);
	}
	long long operator *(const Point&B)const{
		return x*B.x+y*B.y;
	}
	void Read(){
		cin>>x>>y;
	}
	bool operator<(const Point &B)const{
		return x<B.x||x==B.x&&y<B.y;
	}
}P[10000];
int N;
struct C{
	int k;//±êºÅ 
	double Cos;//ÓàÏÒ
	void CalCos(int i){
		Point A(0,1),B=P[i]-P[0];
		Cos=A*B/A.length()/B.length();
		//OUT3(A*B,A.length(),B.length());
		//OUT1(Cos);
	} 
	bool operator<(const C&B)const{
		return Cos>B.Cos;
	}
}AA[10000];
int main(void)
{freopen("1207.txt","r",stdin); 
	while(cin>>N){
		For(i,N) P[i].Read();
		For(i,N) P[i].i=i;
		sort(P,P+N);
		//for(int i=0;i<N;i++) OUT2(i,P[i].i+1);
		for(int i=1;i<N;i++){
			AA[i].k=P[i].i;
			AA[i].CalCos(i);
		}
		//for(int i=0;i<N;i++) OUT2(i,AA[i].k+1);
		sort(AA+1,AA+N);
		//for(int i=1;i<N;i++) OUT3(i,AA[i].k+1,AA[i].Cos);
		printf("%d %d\n",P[0].i+1,AA[N/2].k+1);
	}
	
return 0;
}








