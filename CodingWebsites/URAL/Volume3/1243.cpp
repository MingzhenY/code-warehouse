#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;


int main(void)
{freopen("1243.txt","r",stdin); 
	string a;
	while(cin>>a){
		int n=a.length();
		For(i,n) a[i]-=48;
		int ANS=0;
		For(i,n){
			ANS*=10;
			ANS+=a[i];
			ANS%=7;
		}
		cout<<ANS<<endl;
	}
return 0;
}








