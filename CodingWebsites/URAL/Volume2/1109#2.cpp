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

bool d[1001][1001]; 
bool vis[1001];
int match[1001];
int M,N,K;

bool dfs(int u){
	For(i,N){
		if(d[u][i]&&!vis[i]){
			vis[i]=1;
			if(!~match[i]||dfs(match[i])){
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int MaxMatch(){
	int ANS=0;
	For(i,M){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ANS++;
	}
	return ANS;
}
int main(void)
{freopen("1109.txt","r",stdin); 
	OUT1((sizeof(d)+sizeof(vis)+sizeof(match))/1024);
	while(cin>>M>>N>>K){
		For(i,M){
			For(j,N){
				d[i][j]=0;
			}
		}
		//∂¡»° 
		For(i,K){
			int from,to;
			scanf("%d%d",&from,&to);
			d[from-1][to-1]=1;
		}
		//º∆À„ 
		memset(match,-1,sizeof(match));
		int ANS=MaxMatch();
		memset(vis,0,sizeof(vis));
		for(int i=0;i<N;i++){
			if(~match[i]) {
				vis[match[i]]=1;
			}
			else ANS++;
		}
		For(i,M) if(!vis[i]) ANS++;
		cout<<ANS<<endl;
	}
return 0;
}








