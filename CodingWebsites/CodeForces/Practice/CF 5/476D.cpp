#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,k;
int main(void)
{
	freopen("476D.txt","r",stdin); 
	while(cin>>n>>k){
		printf("%d\n",((n-1)*6+5)*k);
		for(int i=0;i<n;++i){
			printf("%d %d %d %d\n",(i*6+1)*k,(i*6+2)*k,(i*6+3)*k,(i*6+5)*k);
		}
	}
return 0;
}














