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
#include <cstring>
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


int t[4][4],n;
long long _cost[42][5][5]={};
long long cost(int,int,int);//n个东西从i到j 
int main(void)
{
	FOR(i,3) FOR(j,3) cin>>t[i][j];
	memset(_cost,0,sizeof(_cost));
	cin>>n;
	cout<<cost(n,1,3)<<endl;


return 0;
}
long long cost(int n,int i,int j)
{
		if(_cost[n][i][j]) return _cost[n][i][j];
		if(n==1) return _cost[n][i][j]=t[i][j];
		int k;for(k=1;k<4;k++) {if(k==i||k==j) continue;else break;}
		return _cost[n][i][j]=cost(n-1,i,k)+cost(1,i,j)+cost(n-1,k,j);	
}














