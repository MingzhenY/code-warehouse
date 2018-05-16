#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n,m;
char str[50][21];
long long d[1<<20];
int main(void)
{
	freopen("482C.txt","r",stdin); 
	while(~scanf("%d",&n)){
		memset(d,0,sizeof(d));
		for(int i=0;i<n;++i) scanf("%s",str[i]);
		int m=strlen()
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				int same=0;
				for(int k=0;k<m;++k){
					if(str[i][k]==str[j][k]) same|=1<<k;
				}
				d[same]|=1LL <<i;
				d[same]|=1LL <<j;
			}
		}
		
		
	}

		
return 0;
}














