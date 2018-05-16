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

int r[1000000];
int k,p;
int main(void)
{freopen("1375.txt","r",stdin); 
	For(i,1000000) r[i]=-1;
	while(cin>>k>>p){
		For(i,p){
			int D=(int)((i*i)%p);
			if(!~r[D]){
				r[D]=i;
			}
		}
		if(~r[0]&&~r[k]){
			printf("%d %d\n",r[0],r[k]);
			continue;
		}
		int T=0;
		for(int i=1;i<k;i++){
			if(~r[i]&&~r[k-i]){
				printf("%d %d\n",r[i],r[k-i]);
				T=1;break;
			}
		}
		if(T) continue;
		for(int i=k+1;i<=p-1;i++){
			if(~r[i]&&~r[p+k-i]){
				printf("%d %d\n",r[i],r[p+k-i]);
				T=1;break;
			}
		}
		if(T) continue;
		printf("NO SOLUTION\n");
	}
return 0;
}








