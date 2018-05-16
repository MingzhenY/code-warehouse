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

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int maze[100][100];
int N,M;
int main(void)
{freopen("1377.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,N)For(j,M)  maze[i][j]=0;
		int a,b;
		scanf("%d%d",&a,&b); maze[a-1][b-1]=2;
		scanf("%d%d",&a,&b); maze[a-1][b-1]=2;
		int Dir=0;int ALL=0,S=-1,T=-1;
		int x=0,y=0;
		while(1){/*
			OUT1(ALL);
			For(i,N){
				For(j,M){
					printf("%d ",maze[i][j]);
				}cout<<endl;
			}*/
			
			if(maze[x][y]==2) {
				if(!~S) S=ALL;
				else T=ALL;
			}
			maze[x][y]=1;
			if(ALL+1==M*N) break;
			int nx,ny;
			nx=x+dx[Dir],ny=y+dy[Dir];
			while((nx<0||nx>=N||ny<0||ny>=M)||maze[nx][ny]==1) Dir++,Dir%=4,nx=x+dx[Dir],ny=y+dy[Dir];
			//OUT2(ALL,Dir);
			ALL++;
			x=nx;y=ny;
		}
		printf("%d\n",T-S);
	}	
return 0;
}








