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

int n;
int a[1000];
string s; 
int main(void)
{freopen("2023.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<n;++i){
			cin>>s;
			switch(s[0]){
				case 'A':case 'P':case 'O':case 'R':a[i]=1;break;
				case 'B': case 'M': case 'S': a[i]=2;break;
				default:a[i]=3;
			}
		}
		int ANS=abs(a[0]-1);
		for(int i=1;i<n; ++i) ANS+=abs(a[i]-a[i-1]);
		cout<<ANS<<endl;
	}
	
	
	
	
return 0;
}








