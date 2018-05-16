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
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}



long long n,a[100000],b[100000];
int main(void)
{	long long ANS=0;int i;
	cin>>n;
	for(i=0;i<n;i++) scanf("%d",&a[i]); 
	for(i=0;i<n;i++) scanf("%d",&b[i]); 
	for(i=0;i<n;i++)
	{
		if(2*a[i]<b[i]) {ANS--;continue;}
		if(2*a[i]==b[i]) {ANS+=a[i]*a[i];continue;}
		if(b[i]%2==0) ANS+=b[i]*b[i]/4;
		else ANS+=(b[i]*b[i]-1)/4;
		if(b[i]==1) ANS--; 
	}
	cout<<ANS<<endl;
	
	
	return 0;
}















