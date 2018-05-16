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
{freopen("1785.txt","r",stdin); 
	int N;
	while(cin>>N){
		if(N<=4) cout<<"few";
		else if(N<=9) cout<<"several";
		else if(N<=19) cout<<"pack";
		else if(N<=49) cout<<"lots";
		else if(N<=99) cout<<"horde";
		else if(N<=249) cout<<"throng";
		else if(N<=499) cout<<"swarm";
		else if(N<=999) cout<<"zounds";
		else cout<<"legion";
		cout<<endl; 
	}
	
	
	
	
return 0;
}








