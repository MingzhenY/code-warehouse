#include <iostream>
#include <cstdio>
using namespace std;
long long N;
int k;
int a[20],na;
int main(void)
{
	freopen("B.txt","r",stdin); 	
	while(cin>>N>>k){	
		na=0;
		while(N) a[na++]=N%10,N/=10;
			for(int i=na-1;i>=0;i--){
				int t=a[i],I=i;
				for(int j=i;j>=0;j--) if(a[j]>t) t=a[j],I=j;
				if(I==i)  continue;				
				if(k>=i-I){
					int temp=a[I];		
				for(int j=I;j<i;j++) a[j]=a[j]^a[j+1],a[j+1]=a[j]^a[j+1],a[j]=a[j]^a[j+1];							
				k-=i-I;
				}
				else {
				t=a[i],I=i;
				for(int j=i;j>=i-k;j--) if(a[j]>t) t=a[j],I=j;				
				int temp=a[I];
				for(int j=I;j<i;j++) a[j]=a[j+1];
				a[i]=temp;
				k-=i-I;
				}	
			}			
		N=0;
		for(int i=na-1;i>=0;i--){
			N=10*N+a[i];
		}	
		printf("%I64d\n",N);		
	}
return 0;
}

