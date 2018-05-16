#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
int n,m;
int a[100001];
int b[100001]; 
int main(void)
{
	freopen("D.txt","r",stdin); 
	
	while(cin>>n>>m){
		
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&b[i]);
		
		sort(a,a+n);
		sort(b,b+m);
		
		long long ANS=0;
		for(int i=0,j=m-1;i<n&&j>=0;i++,j--){
			if(a[i]>=b[j]) break;
			else ANS+=b[j]-a[i];
		}
		
		
		cout<<ANS<<endl;		
	}

return 0;
}














