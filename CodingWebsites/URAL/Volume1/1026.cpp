#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
int N,K;
int a[100000];
int main(void)
{freopen("1026.txt","r",stdin); 
	memset(a,0,sizeof(a));
	cin>>N;
	For(i,N){
		int b;
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	scanf("%*s");
	cin>>K;
	FOR(i,K){
		int t;
		cin>>t;
		cout<<a[t-1]<<endl;
	}
return 0;
}








