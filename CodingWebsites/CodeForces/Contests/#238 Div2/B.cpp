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


int n;
string a;
int le[3000]={},ri[3000]={}; 
int ANS=0;
int main(void)
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++){
		int count=1;
		if(a[i]=='L'){
			for(int j=i;j>=0;j--) if(a[j]!='R') le[j]=count++;  else break;
		}
		count=1;
		if(a[i]=='R'){
			for(int j=i;j<n;j++) if(a[j]!='L') ri[j]=count++;  else break;
		}
		
	}
	

	
	for(int i=0;i<n;i++){
		if(le[i]==ri[i]) ANS++;
	}
	cout<<ANS<<endl;
	
	return 0;
}















