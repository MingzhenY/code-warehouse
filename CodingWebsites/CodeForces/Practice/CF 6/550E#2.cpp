#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100007
using namespace std;
int N;
int A[maxn];
int Dent[maxn];
bool Zero(){//solve
	if(A[N]) return false;
	int L=-1; 
	for(int i=1;i<N;++i){
		if(!A[i]){L=i;break;}
	}
	if(!~L) return true;
	if(L==N-1) return false;
	if(L^1) Dent[1]=1,Dent[L]=-1;
	if((L+1)^(N-1)) Dent[L+1]=1,Dent[N-1]=-1;
	return true;
}
int main(void)
{
	freopen("550E.txt","r",stdin); 
	while(~scanf("%d",&N)){
		memset(Dent,0,sizeof(Dent));
		int Last1=-1;
		for(int i=1;i<=N;++i){//(Last1,N]
			scanf("%d",&A[i]);
		}
		
		if(Zero()) {
			printf("YES\n");
			for(int i=1;i<=N;++i){
				if(Dent[i]>0){
					for(int j=0;j<Dent[i];++j) printf("(");
				}
				printf("%d",A[i]);
				if(Dent[i]<0){
					for(int j=0;j>Dent[i];--j) printf(")");
				}
				if(i^N) printf("->");
				else printf("\n");
			}
		}
		else printf("NO\n");
	}
return 0;
}

