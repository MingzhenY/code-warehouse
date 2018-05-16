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

double dis[1001][1001];
bool pass[1001][1001];//是否可以往右上走。
int N,M;
double dfs(int i,int j){
	if(dis[i][j]>-0.1) return dis[i][j];
	if(i==M&&j==N) return dis[M][N]=0;
	if(i<M) {
		if(dis[i][j]<0) dis[i][j]=dfs(i+1,j)+100;
		else if(dfs(i+1,j)+100<dis[i][j]) dis[i][j]=dfs(i+1,j)+100;
	}
	if(j<N){
		if(dis[i][j]<0) dis[i][j]=dfs(i,j+1)+100;
		else if(dfs(i,j+1)+100<dis[i][j]) dis[i][j]=dfs(i,j+1)+100;
	}
	if(pass[i][j]){
		if(dis[i][j]<0) dis[i][j]=dfs(i+1,j+1)+200*cos(acos(-1)/4);
		else if(dfs(i+1,j+1)+200*cos(acos(-1)/4)<dis[i][j]) dis[i][j]=dfs(i+1,j+1)+200*cos(acos(-1)/4);
	}
	return dis[i][j];
}
int main(void)
{freopen("1119.txt","r",stdin); 
	while(cin>>M>>N){
		memset(pass,0,sizeof(pass));
		For(i,M+1){
			For(j,N+1) dis[i][j]=-1;
		}
		int T;cin>>T;
		For(i,T){
			int a,b;
			scanf("%d%d",&a,&b);
			pass[a-1][b-1]=1;
		}
		printf("%.0f\n",dfs(0,0));
	}
return 0;
}








