#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,q;
int A[100007];
int main(void)
{
	freopen("498D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i) scanf("%d",&A[i]);
		scanf("%d",&q);
		for(int i=0;i<q;++i){
			char op;int x,y;
			scanf(" %c%d%d",&op,&x,&y);--y;
			if(op=='C'){
				A[x]=y;
			}
			else{
				int K=(y-x)/(A[x]-1);
				int T=(y-x)%(A[x]-1);
				int ANS=K*A[x];
				if(T) ANS+=T+1;
				printf("%d\n",ANS);
			}
		}
	}
	
	
return 0;
}

