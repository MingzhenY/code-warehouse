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
{freopen("1104.txt","r",stdin); 
	string a;
	cin>>a;int High=0;int ALL=0;
	For(i,a.length()){
		if(a[i]<='9') a[i]-=48;
		else a[i]=a[i]-'A'+10;
		if(a[i]>High) High=a[i];
		ALL+=a[i];
	}
	
	for(int k=max(2,High+1);k<=36;k++){
		if(ALL%(k-1)==0) {
			cout<<k<<endl;
			return 0;	
		}
	}
	cout<<"No solution."<<endl;
return 0;
}








