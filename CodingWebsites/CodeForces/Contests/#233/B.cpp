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

long long R[51];


int main(void)
{
	R[1]=1;
	for(int i=2;i<=50;i++){
		R[i]=1;
		for(int j=1;j<i;j++)
			R[i]+=R[j];
			
	}
	long long ANS=0;
	string a;int n;
	cin>>n>>a;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='B') ANS+=R[i+1];
	}
     cout<<ANS<<endl;



return 0;
}















