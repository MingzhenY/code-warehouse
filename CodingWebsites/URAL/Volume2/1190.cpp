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

int N; 
int op[5007];
int weight[5007];
int main(void)
{freopen("1190.txt","r",stdin); 
	while(cin>>N){
		int Cnt=0,Total=0,TotalRev=0;
		for(int i=0;i<N;++i){
			scanf("%*s%d",&op[i]);
			if(op[i]){
				scanf("%d",&weight[i]);
				Total+=(Cnt+1)*weight[i];
				Cnt=0;
			}
			else Cnt++;
		}
		Total+=Cnt;
		Cnt=0;TotalRev=0;
		for(int i=N-1;i>=0;--i){
			if(op[i]){
				TotalRev+=(Cnt+1)*weight[i];
				Cnt=0;
			}
			else Cnt++;
		}
		TotalRev+=Cnt*10000;
		if(Total<=10000&&TotalRev>=10000) printf("YES\n");
		else printf("NO\n");
	}
return 0;
}








