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
int dx[4]={-1, 1, 0, 0};
int dy[4]={ 0, 0, 1,-1};
int de[4]={ 5, 3, 1, 0};
struct Dice{
	char a[6];//a[4]是底 
	void turn(int i){
		switch(i){
			case 0:left();break;
			case 1:right();break;
			case 2:up();break;
			case 3:down();break;
		}
	}
	void left(){char t=a[5];a[5]=a[2];a[2]=a[3];a[3]=a[4];a[4]=t;}
	void right(){char t=a[5];a[5]=a[4];a[4]=a[3];a[3]=a[2];a[2]=t;}
	void up(){char t=a[0];a[0]=a[4];a[4]=a[1];a[1]=a[2];a[2]=t;}
	void down(){char t=a[0];a[0]=a[2];a[2]=a[1];a[1]=a[4];a[4]=t;}
}D;
struct Node{
	vector<short int>path;//记录俩char
	int Dis;Dice Dir;
	void clear(){
		Dis=-1;path.clear();
	}
}game[8][8];
queue<int> Q;
bool Inq[64];
void Bfs(int k){
	int x=k/8,y=k%8;
	OUT2(k/8,k%8);
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<8&&ny>=0&&ny<8){
			int distance=game[x][y].Dis+game[x][y].Dir.a[de[i]];
			if(!~game[nx][ny].Dis||distance<game[nx][ny].Dis){
				switch(i){
					case 0:printf("\t左");break;
					case 1:printf("\t右");break;
					case 2:printf("\t上");break;
					case 3:printf("\t下");break;
				}
				OUT1(distance);
				game[nx][ny].Dis=distance;
				game[nx][ny].Dir=game[x][y].Dir;
				game[nx][ny].Dir.turn(i);
				game[nx][ny].path=game[x][y].path;
				game[nx][ny].path.push_back(8*x+y);
				if(!Inq[nx*8+ny]){
					Q.push(nx*8+ny);Inq[nx*8+ny]=1;
				}
			}
		}
	}
}
int main(void)
{freopen("1016.txt","r",stdin); 
	string a;int Sx,Sy,Dx,Dy;
	cin>>a;Sx=a[0]-'a';Sy=a[1]-'1';
	cin>>a;Dx=a[0]-'a';Dy=a[1]-'1';
	OUT2(Sx,Sy);
	printf("\t");OUT2(Dx,Dy);
	For(i,6) scanf("%d",&D.a[i]);
	memset(Inq,0,sizeof(Inq));
	for(int i=0;i<64;i++) game[i/8][i%8].clear();
	game[Sx][Sy].Dis=D.a[4];game[Sx][Sy].Dir=D;
	Inq[Sx*8+Sy]=1;Q.push(Sx*8+Sy);
	while(!Q.empty()){
		int t=Q.front();Q.pop();
		Inq[t]=0;
		Bfs(t);
		//OUT3(t/8,t%8,game[t/8][t%8].Dis);
	}
	printf("%d",game[Dx][Dy].Dis);
	For(i,game[Dx][Dy].path.size()){
		int t=game[Dx][Dy].path[i];
		printf(" %c%c",t/8+'a',t%8+'1');
	}
	printf(" %c%c",Dx+'a',Dy+'1');
return 0;
}








