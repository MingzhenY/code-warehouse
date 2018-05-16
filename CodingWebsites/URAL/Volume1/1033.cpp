#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct CELL{
	int state;//是否是墙壁 空0 墙1 
	int vis;//使用标记 
	int wall;//周围墙的数量 
};
CELL cell[35][35];

int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void DFS(int x,int y);
int main(void)
{freopen("1033.txt","r",stdin); 
	int M;
	cin>>M;
	//建立 
	for(int i=0;i<=M+1;i++){
		string s;
		if(i&&i<=M) cin>>s;
		for(int j=0;j<=M+1;j++){
			if(i==0||i>M||j==0||j>M) {
				cell[i][j].state=1;continue;
			} 
			cell[i][j].state=(s[j-1]=='#');
			cell[i][j].vis=0;
			cell[i][j].wall=0;
		}
	}/*
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			printf("%4d ",cell[i][j].state);
		}
		cout<<endl;
	}*/
	//DFS 
	DFS(1,1);
	DFS(M,M);
	//计算
	int ANS=0;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			if(cell[i][j].vis) ANS+=cell[i][j].wall;
			//printf("%4d ",cell[i][j].wall);
		}
		//cout<<endl;
	}
	ANS-=4;ANS*=9;
	//输出 
	cout<<ANS<<endl;
return 0;
}
void DFS(int x,int y){
	if(cell[x][y].vis) return;
	cell[x][y].vis=1;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(cell[nx][ny].state) cell[x][y].wall++;
		else if(!cell[nx][ny].vis){
			DFS(nx,ny);
		}
	}
}







