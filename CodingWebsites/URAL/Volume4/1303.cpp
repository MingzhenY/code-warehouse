#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int N,M;
struct ArcNode{
	int from,to;
	int L,R; 
	void init(int a,int b){from=a;to=b;L=max(0,a);R=min(N,b);}
}Arc[100000];
int far[5001];
int path[5001];
int ArcI[5001];

int main(void)
{freopen("1303.txt","r",stdin); 
	
	while(cin>>N){//OUT1(N);
		M=0;int a,b;
		while(~scanf("%d%d",&a,&b)&&(a||b)){//OUT2(a,b);
			if(b <=0||a>=N) continue;
			Arc[M++].init(a,b);
		}
		For(i,5001) far[i]=i;
		For(i,M){
			for(int j=Arc[i].L;j<Arc[i].R;j++){
				if(Arc[i].R>far[j]) {
					far[j]=Arc[i].R;
					ArcI[j]=i; 
				}
			}
		}
		int Cur=0;int ANS=0;
		while(far[Cur]>Cur){
			Cur=far[Cur];
			ANS++;
		}
		if(Cur==N){
			printf("%d\n",ANS);
			Cur=0;
			while(far[Cur]>Cur){
				printf("%d %d\n",Arc[ArcI[Cur]].from,Arc[ArcI[Cur]].to); 
				Cur=far[Cur];
			}	
		}
		else printf("No solution\n");
	}
return 0;
}








