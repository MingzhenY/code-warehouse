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

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int next[6][4]={
{0,3,0,2},{1,2,1,3},{5,0,4,1},
{4,1,5,0},{2,4,3,4},{3,5,2,5}
};
struct Node{
	int D;
	bool to[4];
	void init(){D=-1;to[0]=to[1]=to[2]=to[3]=1;}
}node[6][11][11];
int X,Y,Sx,Sy,Dx,Dy;
queue<int>Q;
int bfs(int d,int x,int y){
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>0&&nx<=X&&ny>0&&ny <=Y){
			if(node[d][x][y].to[k]){
				int &D=node[next[d][k]][nx][ny].D;
				if(!~D||node[d][x][y].D+1<D){
					D=node[d][x][y].D+1;
					Q.push((next[d][k]<<8)+(nx<<4)+ny);
				}
			}
		}
	}
}
int main(void)
{freopen("1301.txt","r",stdin); 
	scanf("%d%d%d%d%d%d%*c%*c",&X,&Y,&Sx,&Sy,&Dx,&Dy);
	for(int i=0;i<6;i++) for(int j=1;j<=10;j++) for(int k=1;k<=10;k++) node[i][j][k].init();
	string str;int a,b;
	while(cin>>str&&str[0]!='h'){
		a=atoi(str.c_str());scanf("%d",&b);
		for(int i=0;i<6;i++) node[i][a][b].to[3]=node[i][a+1][b].to[1]=0; 
	}
	while(cin>>a>>b){
		for(int i=0;i<6;i++) node[i][a][b].to[2]=node[i][a][b+1].to[0]=0; 
	}
	Q.push((3<<8)+(Sx<<4)+Sy);node[3][Sx][Sy].D=0;
	while(!Q.empty()){
		int D=Q.front();Q.pop();
		int d,x,y;
		y=D&15;D>>=4;
		x=D&15;D>>=4;
		d=D&15;
		bfs(d,x,y);
	}
	if(~node[3][Dx][Dy].D){
		printf("%d\n",node[3][Dx][Dy]);
	}
	else{
		printf("No solution\n");
	}
	
return 0;
}








