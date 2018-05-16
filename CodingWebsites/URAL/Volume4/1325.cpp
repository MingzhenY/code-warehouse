#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,M;
int Sx,Sy,Dx,Dy;
int grid[501][501];
int dis[501][501];
int change[501][501];
bool inq[251001] ;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,1,-1,-1,0,1};
queue<int>Q;
void bfs(int x,int y){
	For(i,8){ 
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=1&&nx<=N&&ny>=1&&ny<=M){
			if(grid[nx][ny]){
				int D=dis[x][y]+1;
				int C=change[x][y]+(grid[x][y]!=grid[nx][ny]);
				int X=nx*501+ny;
				if(~dis[nx][ny]){
					if(C <change[nx][ny]||C==change[nx][ny]&&D <dis[nx][ny]){
						dis[nx][ny]=D;
						change[nx][ny]=C;
						if(!inq[X]) Q.push(X),inq[X]=1;
					}
				}
				else{
					dis[nx][ny]=D;
					change[nx][ny]=C;
					if(!inq[X]) Q.push(X),inq[X]=1;
				}			
			}			
		}
	}
}
int main(void)
{freopen("1325.txt","r",stdin); 
	while(cin>>N>>M){
		scanf("%d%d%d%d",&Sx,&Sy,&Dx,&Dy);
		FOR(i,N){
			FOR(j,M){
				scanf(" %c",&grid[i][j]);
				grid[i][j]-=48;
			}
		}
		memset(dis,-1,sizeof(dis));memset(inq,0,sizeof(inq));
		Q.push(Sx*501+Sy);dis[Sx][Sy]=1;change[Sx][Sy]=0;inq[Sx*501+Sy]=1;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			inq[x]=0;
			int y=x%501;x/=501;
			bfs(x,y);
		}
		if(~dis[Dx][Dy]) printf("%d %d\n",dis[Dx][Dy],change[Dx][Dy]);
		else printf("0 0\n");
	}
return 0;
}








