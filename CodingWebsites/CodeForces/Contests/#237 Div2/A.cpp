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
char a[300][300];
int main(void)
{
	cin>>n;
	int i,j;
	int T=1;
	for(i=0;i<n;i++){
			scanf("%*c");
		for(j=0;j<n;j++){
			scanf("%c",&a[i][j]);
		}
	
	}
/*	
	cout<<"printing:\n";
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++){
		printf("%c",a[i][j]);
		}
		cout<<endl;
	}
	cout<<"printEnd"<<endl;
	*/
	for(i=0;i<n;i++){
		if(!T) break;
		for(int j=0;j<n;j++){
		
			
			if(i==j||i+j==n-1) {
				if(a[i][j]!=a[0][0]) {
					T=0;break;
				}
			}
			else{
				if(a[i][j]==a[0][0]||a[i][j]!=a[0][1]) {
					T=0;break;
				}
			}
		}
	}
	
	if(T) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;




return 0;
}















