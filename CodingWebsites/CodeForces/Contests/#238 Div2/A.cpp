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

int n;
int a[100][100],b[100],ans[100];
int main(void)
{
	cin>>n;
	for(int i=0;i<n;i++){
		int r;cin>>r;
		for(int j=0;j<r;j++) a[i][j]=1;
	}
	
	for(int i=0;i<100;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==1){
				a[j][i]=0;
				b[i]++;
			}
		}
		for(int j=1;j<=b[i];j++){
			a[n-j][i]=1;
		}
	}
	for(int i=0;i<n;i++){
		ans[i]=0;
		for(int j=0;j<100;j++){
			ans[i]+=a[i][j];
		}
	}
	printf("%d",ans[0]);
	for(int i=1;i<n;i++){
		printf(" %d",ans[i]);
	}
	cout<<endl;
return 0;
}















