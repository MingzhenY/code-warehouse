#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 500007
using namespace std;
int next[maxn];
int N,M;
int main(void)
{
	freopen("13E.txt","r",stdin); 
	while(~scanf("%d%d",&N,&M)){
		for(int i=1;i<=N;++i) scanf("%d",&next[i]);
		for(int i=1;i<=M;++i){
			int op,a,b;
			scanf("%d",&op);
			if(op){scanf("%d",&a);
				int X=a,PreX,ANS=0;
				while(X<=N){
					PreX=X;
					ANS++;
					X+=next[X];
				}
				printf("%d %d\n",PreX,ANS);
			}
			else{scanf("%d%d",&a,&b);
				next[a]=b;
			}
		}
	}
return 0;
}


