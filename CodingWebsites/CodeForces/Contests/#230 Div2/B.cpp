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

double A[171][171],B[171][171],W[171][171];
int n;

int main(void)
{
cin>>n;
FOR(i,n) FOR(j,n) scanf("%lf",&W[i][j]);

FOR(i,n) FOR(j,n) { A[i][j]=(W[i][j]+W[j][i])/2;B[i][j]=(W[i][j]-W[j][i])/2;}

FOR(i,n) {
	FOR(j,n) {
		printf("%.8lf",A[i][j]);
		if(j!=n) printf(" ");
		else printf("\n");
		}
	}
	FOR(i,n) {
	FOR(j,n) {
		printf("%.8lf",B[i][j]);
		if(j!=n) printf(" ");
		else printf("\n");
		}
	}


return 0;
}















