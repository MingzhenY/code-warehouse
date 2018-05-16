#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b){
	while(b){long long t=a%b;a=b;b=t;}
	return a;
}
int main(void)
{
	freopen("A.txt","r",stdin); 
	long long l,r;
	while(cin>>l>>r){
		if(l&1){
			if(r-l>=3) printf("%I64d %I64d %I64d\n",l+1,l+2,l+3);
			else if(r==l+2){
				int a=gcd(l,l+1),b=gcd(l,l+2),c=gcd(l+1,l+2);
				if(a==1&&b==1&&c>1) printf("%I64d %I64d %I64d\n",l+1,l,l+2);
				else if(a==1&&c==1&&b>1)printf("%I64d %I64d %I64d\n",l,l+1,l+2);
				else if(b==1&&c==1&&a>1)printf("%I64d %I64d %I64d\n",l,l+2,l+1);
				else printf("-1\n");
			}
			else printf("-1\n");
		}
		else{
			if(r-l>=2) printf("%I64d %I64d %I64d\n",l,l+1,l+2);
			else printf("-1\n");
		}
	} 

		
return 0;
}














