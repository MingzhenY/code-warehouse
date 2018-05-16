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

const int x[]={0,2,3,5,7,13,17,19,31,61,89,
               107,127,521,607,1279,2203,2281,3217,4253,4423,
               9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,
               216091,756839,859433,1257787,1398269,2976221,3021377,6972593};
int main(void)
{freopen("1352.txt","r",stdin); 
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		cout<<x[n]<<endl;
	}
	
	
return 0;
}








