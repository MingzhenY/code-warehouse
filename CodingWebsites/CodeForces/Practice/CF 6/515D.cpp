#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int n,m;

struct Node{
	int deg;
	bool d[4];
	bool On;
	void Init(){deg=0;On=1;d[0]=d[1]=d[2]=d[3]=0;}
}node[2000][2000];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void DArc(int from,int to){
	int nx,ny,tx,ty;
	nx=from/m;ny=from%m;
	tx=to/m;ty=to%m;
	for(int i=0;i<4;++i){
		if(nx+dx[i]==tx&&ny+dy[i]==ty) node[nx][ny].d[i]=1;
		if(tx+dx[i]==nx&&ty+dy[i]==ny) node[tx][ty].d[i]=1;
	}
	node[nx][ny].deg++;
	node[tx][ty].deg++;
}
char str[2000][2001];
queue<int> One;
int ALL=0;

void Del(int x,int y){
	node[x][y].On=0;
	for(int i=0;i<4;++i){
		if(node[x][y].d[i]){
			int nx=x+dx[i],ny=y+dy[i];
			if(str[nx][ny]=='.'&&node[nx][ny].On){
				node[nx][ny].deg--;
				if(node[nx][ny].deg==1) One.push(nx*m+ny);
			}
		}
	}
}
int main(void)
{
	freopen("515D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		ALL=0;
		for(int i=0;i<n;++i) scanf("%s",str[i]);
		for(int i=0;i<n;++i) 
			for(int j=0;j<m;++j) 
				node[i][j].Init(),ALL+=(str[i][j]=='.');
		//连接横向边 
		for(int i=0;i<n;++i){
			for(int j=0;j<m-1;++j){
				if(str[i][j]=='.'&&str[i][j+1]=='.')
					DArc(i*m+j,i*m+j+1);
			}
		}
		//连接纵向边 
		for(int i=0;i<n-1;++i){
			for(int j=0;j<m;++j){
				if(str[i][j]=='.'&&str[i+1][j]=='.')
					DArc(i*m+j,(i+1)*m+j);
			}
		}
		while(!One.empty()) One.pop();
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(node[i][j].deg==1){
					One.push(i*m+j);
				}
			}
		}
		while(!One.empty()){
			int cnt=One.front();One.pop();
			int nx=cnt/m,ny=cnt%m;
			if(!node[nx][ny].On) continue;
			for(int k=0;k<4;++k){
				if(node[nx][ny].d[k]){
					int tx=nx+dx[k],ty=ny+dy[k];
					if(str[tx][ty]=='.'&&node[tx][ty].On){
						for(int i=0;i<4;++i){
							if(tx==nx+dx[i]&&ty==ny+dy[i]){
								switch(i){
									case 0:str[nx][ny]='v';str[tx][ty]='^';break;
									case 1:str[nx][ny]='^';str[tx][ty]='v';break;
									case 2:str[nx][ny]='>';str[tx][ty]='<';break;
									case 3:str[nx][ny]='<';str[tx][ty]='>';break;
								}
							}
						}
						Del(nx,ny);Del(tx,ty);ALL-=2;
						break;
					}
				}
			}
		} 
		if(ALL){
			printf("Not unique\n");
		}
		else{
			for(int i=0;i<n;++i){
				printf("%s\n",str[i]);
			}
		}
	}
return 0;
}














