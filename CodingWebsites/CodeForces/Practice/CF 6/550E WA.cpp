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
int Pre[maxn];//previous One
int LM[maxn];
int RM[maxn];
int Dent[maxn];
bool Zero(){//solve
	if(A[N]) return false;
	int t=N;
	int Z=1;
	while(~Pre[t]){
		Z+=t-Pre[t]-1;
		t=Pre[t];
		if(~Z&1){
			int L=t,R=RM[t+1];
			Dent[L]++;Dent[R]--;
			RM[L]=R;LM[R]=L;	
		}
		else{
			Dent[1]++;
			Dent[t]--;
			return true;
		}
	}
	Z+=t-1;
	if(Z&1) return true;
	return false;
}
int main(void)
{
	freopen("550E.txt","r",stdin); 
	while(~scanf("%d",&N)){
		memset(Dent,0,sizeof(Dent));
		int Last1=-1;
		for(int i=1;i<=N;++i){//(Last1,N]
			scanf("%d",&A[i]);
			Pre[i]=Last1;
			RM[i]=LM[i]=i;
			if(A[i]) Last1=i;
		}
		int Z=0;
		for(int i=N;i>=1;--i){
			Z+=A[i]==0;
			if(Z>=3&&(Z&1)){
				if(A[i]==0&&A[i+1]==0){
					
					break;
				}
			}
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

