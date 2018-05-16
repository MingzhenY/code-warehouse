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

int N;
long long a[25001]; 
long long s[25001];
long long ss[25001];
int main(void)
{freopen("1290.txt","r",stdin); 
	while(cin>>N){
		FOR(i,N) scanf("%d",&a[i]);
		a[0]=0;
		sort(a,a+N+1);
		for(int i=1;i<=N;i++){
			s[i]=a[i]-a[i-1];
			//OUT2(i,s[i]);
		}
		ss[0]=0;
		for(int i=1;i<=N;i++){
			ss[i]=ss[i-1]+s[i];
			//OUT2(i,ss[i]);
		}
		
		for(int i=N;i>0;i--){
			if(ss[i]) cout<<ss[i]<<endl;
		}
		
	}
	
	
	
	
return 0;
}








