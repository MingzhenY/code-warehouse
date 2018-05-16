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

int f(char,char);

int main(void)
{
	
//	cout<<f('8','[')<<endl;
//	freopen("A.txt","r",stdin);
string a,b;
int T=0;
cin>>a>>b;
int n=a.size();
for(int i=0;i<n;i+=2){
	T+=f(a[i],b[i]);
}
if(T>0) cout<<"TEAM 1 WINS"<<endl;
else if(T==0) cout<<"TIE"<<endl;
else cout<<"TEAM 2 WINS"<<endl;




return 0;
}

int f(char a,char b){
	if(a=='[') a=2;
	else if(a=='(') a=1;
	else a=0;
	if(b=='[') b=2;
	else if(b=='(') b=1;
	else b=0;
	if(a==b) return 0;
	if(a-b==1) return 1;
	if(a-b==2) return -1;
	if(b-a==1) return -1;
	if(b-a==2) return 1;
}













