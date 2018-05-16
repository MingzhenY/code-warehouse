#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define  inf  0x3fffffff
#define FOR(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;} 


double a,d;
int n;
void f(double);

int main(void)
{
	cin>>a>>d>>n;
	double cover=0;
	for(int i=1;i<=n;i++){
		cover+=d;
		int times=(int)(cover/a/4);
		cover-=4*a*times;
		f(cover);
	}




return 0;
}
void f(double k){
	double x=-1,y=-1;
	if(k<a) {
		x=k;y=0;
	}
	else if(k<2*a){
		x=a;y=k-a;
	}
	else if(k<3*a){
		x=3*a-k;y=a;
	}
	else {
		x=0;y=4*a-k;
	}
	printf("%.10lf %.10lf\n",x,y);
}














