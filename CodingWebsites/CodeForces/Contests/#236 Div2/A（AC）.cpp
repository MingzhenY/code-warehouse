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

int k,a,b,v;

int main(void)
{
	
	cin>>k>>a>>b>>v;
	
	int n;int MAX=k*(b/(k-1))+b%(k-1)+1;
	a%v==0?n=a/v:n=a/v+1;
	if(n<MAX) {
		cout<<(a%(k*v)==0?a/(k*v):a/(k*v)+1)<<endl; 
	}
	else cout<<b/(k-1)+1+n-MAX<<endl;


    	//cout<<b/(k-1)+n-k*(b/(k-1))-b%(k-1)<<endl;


return 0;
}















