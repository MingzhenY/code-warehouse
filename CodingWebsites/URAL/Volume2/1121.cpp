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

int S[151][151];
int ANS[151][151][6];
int vis[151][151];
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,1,-1};
int Mark;int H,W;
queue<int> Q;
void BFS(int x,int y,int dis,int Branch){
	if(vis[x][y]==Mark) return;
	vis[x][y]=Mark;
	ANS[x][y][dis]|=Branch;
	if(dis==5) return;
	for(int dir=0;dir<4;++dir){
		int nx=x+dx[dir],ny=y+dy[dir];
		if(nx>=0&&nx<H&&ny>=0&&ny<W){
			if(vis[nx][ny]!=Mark){
				Q.push(((dis+1)<<16)|(nx<<8)|(ny));
			}
		}
	}
}
int main(void)
{freopen("1121.txt","r",stdin); 
	while(~scanf("%d%d",&H,&W)){
		memset(ANS,0,sizeof(ANS));
		memset(vis,0,sizeof(vis));Mark=1;
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				scanf("%d",&S[i][j]);
			}
		}
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				if(S[i][j]) {
					while(!Q.empty()) Q.pop();
					Q.push((i<<8)+j);
					while(!Q.empty()){
						int Cnt=Q.front();Q.pop();
						int dis=Cnt>>16,x=(Cnt>>8)&255,y=Cnt&255;
						BFS(x,y,dis,S[i][j]);
					}
					++Mark;
				}
			}
		}
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				if(S[i][j]) printf("-1");
				else if(ANS[i][j][1]) printf("%d",ANS[i][j][1]);
				else if(ANS[i][j][2]) printf("%d",ANS[i][j][2]);
				else if(ANS[i][j][3]) printf("%d",ANS[i][j][3]);
				else if(ANS[i][j][4]) printf("%d",ANS[i][j][4]);
				else if(ANS[i][j][5]) printf("%d",ANS[i][j][5]);
				else printf("0");
				if(j+1==W) printf("\n");
				else printf(" ");
			}
		}
	}
	
	
	
	
return 0;
}








