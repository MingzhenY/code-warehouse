#include <iostream>
#include <cstdio>
#include <cmath>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)

using namespace std;
int n;
long long a[50000];
int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>n){
		long long ALL=0,D=0;
		For(i,n) {
			scanf("%I64d",&a[i]),ALL+=a[i];
			if(ALL>100*10000*10000) {
				D+=ALL/n;ALL-=D*n;
			}
		}
		D+=ALL/n;
		
		 long long ANS=0;
		For(i,n-1){
			long long T=D-a[i];
			
			a[i]+=T;a[i+1]-=T;
			ANS+=T>0?T:-T;
		}
		
		cout<<ANS<<endl;
	}
return 0;
}
