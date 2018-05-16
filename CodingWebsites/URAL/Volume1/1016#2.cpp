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
	int a[6];//按照题目给的顺序，分别为前，后，上，右，下，左 
	int next[4];//四个方向旋转后的编号
	void turn(int i){
		switch(i){
			case 0:left();break;
			case 1:right();break;
			case 2:up();break;
			case 3:down();break;
		}
	}
	void left(){int t=a[5];a[5]=a[2];a[2]=a[3];a[3]=a[4];a[4]=t;}
	void right(){int t=a[5];a[5]=a[4];a[4]=a[3];a[3]=a[2];a[2]=t;}
	void up(){int t=a[0];a[0]=a[4];a[4]=a[1];a[1]=a[2];a[2]=t;}
	void down(){int t=a[0];a[0]=a[2];a[2]=a[1];a[1]=a[4];a[4]=t;}
	bool operator ==(const Dice&B)const{
		int T=0;
		for(int i=0;i<6;i++) T+=a[i]==B.a[i];
		return T==6;
	}
	void show(){
		printf("\t(%d,%d,%d,%d,%d,%d)\n",a[0],a[1],a[2],a[3],a[4],a[5]);
	}
}D[24];int Dn;
struct Node{
	int path;
	int Dis;
	void init(int k){
		Dis=-1;path=k;
	}
}game[1536];
queue<int> Q;
bool inq[1536];
void Bfs(int k){
	int tempk=k;
	int index=tempk/64;tempk%=64;
	int x=tempk/8,y=tempk%8;
	for(int i=0;i<4;i++){//向4个方向扩展 
		int nx=x+dx[i],ny=y+dy[i];
		int Next=D[index].next[i]*64+nx*8+ny;//计算下个节点的编号 
		if(nx>=0&&nx<8&&ny>=0&&ny<8){//如果在棋盘内 
			int Distance=game[k].Dis+D[index].a[de[i]];
			if(!~game[Next].Dis||Distance<game[Next].Dis){//如果未走过或者路径更短，更新 
				game[Next].Dis=Distance;
				game[Next].path=game[k].path;
				game[Next].path=k;
				if(!inq[Next]) Q.push(Next),inq[Next]=1;//若未入队，入队 
			}
		}
	}
}
void F(int i){//输出路径 
	if(i!=game[i].path) F(game[i].path);
	int t=i%64;
	printf(" %c%c",t/8+'a',t%8+'1');
}
int main(void)
{freopen("1016.txt","r",stdin);
	//处理输入 
	string a;int Sx,Sy,Dx,Dy;
	cin>>a;Sx=a[0]-'a';Sy=a[1]-'1';
	cin>>a;Dx=a[0]-'a';Dy=a[1]-'1';
	for(int i=0;i<6;i++) scanf("%d",&D[0].a[i]);
	//设置Dices
	Dn=1;
	for(int i=0;i<Dn;i++){//对于每个状态（开始只有一个状态） 
		for(int k=0;k<4;k++){// 向四个方向滚动 
			Dice temp=D[i];
			temp.turn(k);
			int Target=-1;
			for(int j=0;j<Dn;j++){//若出现过，记录编号
				if(D[j]==temp) {
					Target=j;break;
				}
			}
			if(!~Target){//若没出现过，用新的编号 
				Target=Dn++;
				D[Target]=temp;
			}
			D[i].next[k]=Target;//记录i往四个方向转动后的状态的编号 
		}
	}
	//显示Dices
	/* 
	for(int i=0;i<Dn;i++){
		printf("%d:",i);D[i].show();
		for(int k=0;k<4;k++) printf("->%d",D[i].next[k]);
		cout<<endl;
	}*/
	
	//计算  (SPFA)
	for(int i=0;i<1536;i++) game[i].init(i);
	memset(inq,0,sizeof(inq));
	Q.push(Sx*8+Sy);inq[Sx*8+Sy]=1;
	game[Sx*8+Sy].Dis=D[0].a[4];
	while(!Q.empty()){
		int cnt=Q.front();Q.pop();
		inq[cnt]=0;
		Bfs(cnt);
	}
	//搜索答案 
	int ANS=-1;int ANSI=-1;
	for(int i=0;i<Dn;i++){
		if(~game[i*64+Dx*8+Dy].Dis){
			if(!~ANS||game[i*64+Dx*8+Dy].Dis<ANS){
				ANS=game[i*64+Dx*8+Dy].Dis;
				ANSI=i*64+Dx*8+Dy;
			}	
		}
	}
	//输出答案 
	cout<<ANS;
	F(ANSI);
	cout<<endl;
return 0;
}








