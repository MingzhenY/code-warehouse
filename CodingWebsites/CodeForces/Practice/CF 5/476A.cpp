#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{
	freopen("476A.txt","r",stdin); 
	int n,m;
	while(cin>>n>>m){
		int D=ceil((double)n/m/2.0);
		if(D&&D*m <=n) printf("%d\n",D*m);
		else printf("-1\n");
	}
return 0;
}














