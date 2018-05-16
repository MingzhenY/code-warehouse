#include <iostream>
#include <cstdio>
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
int a[100001];
int n;
int main(void)
{
	freopen("A.txt","r",stdin); 
	
	while(cin>>n){
		FOR(i,n) a[i]=1;
		int t;
		FOR(i,n) scanf("%d",&t),a[t]=0;
		int ANS;
		FOR(i,n) if(a[i])  ANS=i; 
		
		cout<<ANS<<endl;
		
	}
return 0;
}














