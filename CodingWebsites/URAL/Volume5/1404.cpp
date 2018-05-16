#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

string str;int n;
int main(void)
{freopen("1404.txt","r",stdin); 
	while(cin>>str){
		n=str.length();
		for(int i=0;i<n;i++) str[i]-='a';
		for(int i=n-1;i>=1;--i) {
			str[i]=str[i]-str[i-1];
			while(str[i]<0) str[i]+=26;
		}
		str[0]-=5;while(str[0]<0) str[0]+=26;
		for(int i=0;i<n;i++) str[i]+='a';
		cout<<str<<endl;
	}
	
	
	
	
return 0;
}








