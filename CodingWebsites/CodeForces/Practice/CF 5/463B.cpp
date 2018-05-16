#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main(void)
{
	freopen("463B.txt","r",stdin); 
	while(cin>>n){
		int maxn=0,t;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			maxn=max(maxn,t);
		}
		printf("%d\n",maxn);
	}
return 0;
}














