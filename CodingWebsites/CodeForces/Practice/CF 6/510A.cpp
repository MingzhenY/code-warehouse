#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
	freopen("510A.txt","r",stdin); 
	int n,m;char a[51][51];
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			if(i&1){
				for(int j=1;j<=m;++j) a[i][j]='#';
			}
			else{
				for(int j=1;j<=m;++j) a[i][j]='.';
				if((i>>1)&1){
					a[i][m]='#';
				}
				else{
					a[i][1]='#';
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	} 

		
return 0;
}














