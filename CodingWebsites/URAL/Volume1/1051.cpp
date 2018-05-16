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
{freopen("1051.txt","r",stdin); 
	int m,n; 
	while(cin>>m>>n){
		if(m>n) swap(m,n);
		int ANS;
		if(m==1) ANS=(n+1)>>1;
		else{
			if(m%3==0||n%3==0) ANS=2;
			else ANS=1;
		}
		cout<<ANS<<endl;
	}
return 0;
}








