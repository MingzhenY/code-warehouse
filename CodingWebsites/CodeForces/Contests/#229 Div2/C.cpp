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
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
int abs(int a){if(a>=0) return a;else return -a;} 



int n,k,w,l,r;
string a;

int main(void)
{int ans ;
	cin>>n>>k>>w;
	cin>>a;
	while(w--)
	{ans=0;
	cin>>l>>r;
	l;r;
	
	
	for(int i=r;i>=l;i--)
	{
		if((r-i)%k==0) continue;//if(a[i-1]==48) ans++;
		if(a[i-1]==49) ans++;
	}	
	
	cout<<ans<<endl;
	}












return 0;
}














