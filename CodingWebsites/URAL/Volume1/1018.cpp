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
struct Node{
	int apple;//苹果数量
	int ls,rs;//左右子树 
	void init(){apple=0;ls=-1;rs=-1;}
}node[100];
int vis[100];
int N,Q;
int dp[100][100];
int DFS(int i,int j){
	if(i<0) return 0;
	if(~dp[i][j]) return dp[i][j];
	if(j==0) return dp[i][j]=0;
	if(j==1) return dp[i][j]=node[i].apple;
	
	int ANS=0;
	for(int k=0;k<j;k++){
		ANS=max(ANS,DFS(node[i].ls,k)+DFS(node[i].rs,j-k-1));
	}
	return dp[i][j]=ANS+node[i].apple;
}

int main(void)
{freopen("1018.txt","r",stdin); 
	while(cin>>N>>Q){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<N;i++) node[i].init();
		vis[0]=1;
		for(int i=1;i<N;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);a--;b--;
			int old,now;
			if(vis[a]) old=a,now=b;
			else old=b,now=a;
			node[now].apple=v;vis[now]=1;
			if(~node[old].ls) node[old].rs=now;
			else node[old].ls=now;
		}
		memset(dp,-1,sizeof(dp));
		cout<<DFS(0,Q+1)<<endl;
	}
return 0;
}








