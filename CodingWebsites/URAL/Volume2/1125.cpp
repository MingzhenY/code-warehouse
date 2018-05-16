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
#define eps 1e-9
using namespace std;

char G[51][51];
int times[51][51];
int M,N; 
bool IsS2[250001];
int main(void)
{freopen("1125.txt","r",stdin); 
	memset(IsS2,0,sizeof(IsS2));
	for(int i=1;i<=500;++i){
		IsS2[i*i]=true;
	}
	while(~scanf("%d%d",&M,&N)){
		for(int i=0;i<M;++i) scanf("%s",G[i]);
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				G[i][j]=G[i][j]=='B';
				scanf("%d",&times[i][j]);
				times[i][j]&=1;
			}
		} 
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				if(!times[i][j]) continue;
				G[i][j]=1-G[i][j];
				for(int ni=0;ni<M;++ni){
					for(int nj=0;nj<N;++nj){
						int D=(ni-i)*(ni-i)+(nj-j)*(nj-j);
						if(IsS2[D]) G[ni][nj]=1-G[ni][nj];
					}
				}
			}
		}
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				G[i][j]=G[i][j]?'B':'W';
			}
		} 
		for(int i=0;i<M;++i) printf("%s\n",G[i]);
	}
return 0;
}








