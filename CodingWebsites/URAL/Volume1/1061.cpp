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

char str[100007];
int n,k;
int sum[100007];
int cnt[100007];
int main(void)
{freopen("1061.txt","r",stdin); 
	while(cin>>n>>k){
		for(int i=1;i<=n;++i) scanf(" %c",&str[i]);
		sum[0]=cnt[0]=0;
		for(int i=1;i<=n;++i){
			sum[i]=sum[i-1]+str[i]-48;
			cnt[i]=cnt[i-1]+(str[i]=='*');
		}
		int L=0,Cost=0x7fffffff;
		for(int i=1;i+k-1<=n;++i){
			if(cnt[i-1]==cnt[i+k-1]&&sum[i+k-1]-sum[i-1]<Cost){
				Cost=sum[i+k-1]-sum[i-1];
				L=i;
			}
		}
		cout<<L <<endl;
	}
return 0;
}








