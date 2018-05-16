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
int Ones[501][501];
int Zeros[501][501];
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,1,-1,-1,0,1};
void init(int x,int y){
	Ones[x][y]=Zeros[x][y]=0;
	For(i,8){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=1&&nx<=N&&ny>=1&&ny<=M){
			if(grid[nx][ny]){
				if(grid[nx][ny]==grid[x][y]){
					Ones[x][y]++;
				}
				else Zeros[x][y]++;
			}
		}
	}
}

vector<int> Step[250001];
void bfs(int x,int y,int t,int p){
	For(i,8){ 
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=1&&nx<=N&&ny>=1&&ny<=M){
			if(grid[nx][ny]){
				if(t==(grid[x][y]!=grid[nx][ny])){
					if(!~dis[nx][ny]||dis[x][y]<dis[nx][ny]){
						//printf("\t");OUT2(nx,ny);
						dis[nx][ny]=dis[x][y]+1;
						change[nx][ny]=change[x][y]+t;
						if(t) {
							if(Zeros[nx][ny]>0) Step[p].push_back(nx*501+ny);
						}
						if(!t) {
							bfs(nx,ny,t,p);
							if(Ones[nx][ny]>0) Step[p].push_back(nx*501+ny);
						}
					}		
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
		FOR(i,N){
			FOR(j,M){
				if(grid[i][j]) init(i,j);
			}
		}
		memset(dis,-1,sizeof(dis));memset(change,-1,sizeof(change));
		Step[0].push_back(Sx*501+Sy);dis[Sx][Sy]=1;change[Sx][Sy]=0;
		For(i,Step[0].size()){
				int x=Step[0][i],y=x%501;x/=501;
				bfs(x,y,0,0);
			}
		for(int p=1;p<=N*M;p++){//if(p==2) break;
			int n=Step[p-1].size();
			//printf("\n\tP=%d,任务一：\n",p);
			For(i,n){
				int x=Step[p-1][i],y=x%501;x/=501;
				bfs(x,y,1,p);
			}
			n=Step[p].size();
			//printf("\n\tP=%d,任务二：\n",p);
			For(i,n){
				int x=Step[p][i],y=x%501;x/=501;
				bfs(x,y,0,p);
			}
			//printf("\n\t显示开始：\n");
		
			if(~dis[Dx][Dy] ) break;
		}
		/*
		FOR(i,N){
			FOR(j,M){
				if(~dis[i][j]) printf("%2d ",dis[i][j]);
				else printf("   ");
			}cout<<endl;
		}
		FOR(i,N){
			FOR(j,M){
				if(~change[i][j]) printf("%2d ",change[i][j]);
				else printf("   ");
			}cout<<endl;
		}	*/
		
		if(~dis[Dx][Dy]) printf("%d %d\n",dis[Dx][Dy],change[Dx][Dy]);
		else printf("0 0\n");
	}
return 0;
}








