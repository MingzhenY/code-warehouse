#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue> 
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct P{
	int x, y;
	P(){}
	P(int x,int y):x(x),y(y){}
};
int B[11][11];
int vis[11][11];
int N; int ALL;
queue <P>Q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char D[4]={'R','T','L','B'};
void BFS(int x,int y){
	
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(B[nx][ny]&&!vis[nx][ny]) {
			cout<<D[k];
			Q.push(P(nx,ny));
			vis[nx][ny]=1;
		}
		
	}
	if(ALL<N) cout<<",\n";
	else cout<<".\n";
}
string str;int T=-1; 
void BFS2(int x,int y){
	B[x][y]=1;ALL++;
	string temp;
	if(!~T) temp=str,T=1;
	else{
		if(T>0) cin>>temp;
		else return;
	}
	
	for(int i=0;i<temp.length();i++){
		switch(temp[i]){
			case 'R':Q.push(P(x+dx[0],y+dy[0]));break;
			case 'T':Q.push(P(x+dx[1],y+dy[1]));break;
			case 'L':Q.push(P(x+dx[2],y+dy[2]));break;
			case 'B':Q.push(P(x+dx[3],y+dy[3]));break;
			case ',':break;
			case '.':T=0;break;
		}
	}
}
int main(void)
{freopen("1008.txt","r",stdin); 

	memset(B,0,sizeof(B));
	memset(vis,0,sizeof(vis));
	//建图 
	int prex,prey;
	cin>>prex>>prey>>str;
	int minx=inf,miny=inf;
	if(str[0]>='0'&&str[0]<='9'){//格式一输入 
		N=prex;int x,y;
		x=prey;y=atoi(str.c_str());
		if(x<minx){minx=x;miny=y;}
		if(x==minx&&y<miny) miny=y;
		B[x][y]=1;
		for(int i=1;i<N;i++){
		cin>>x>>y;
		if(x<minx){minx=x;miny=y;}
		if(x==minx&&y<miny) miny=y;
		B[x][y]=1;
		}
	}
	else{//格式二输入 
		minx=prex;miny=prey;ALL=0;
		Q.push(P(minx,miny));
		while(!Q.empty()){
			P temp=Q.front();Q.pop();
			BFS2(temp.x,temp.y);
		}
		
		printf("%d\n",ALL);
		for(int i=1;i<11;i++){
			for(int j=1;j<11;j++){
				if(B[i][j]) printf("%d %d\n",i,j);
			}
		}
		return 0;
	}
		
		//格式二的计算+输出 
	printf("%d %d\n",minx,miny);
	Q.push(P(minx,miny));vis[minx][miny]=1;ALL=0;
	while(!Q.empty()){ALL++;
		P temp=Q.front();Q.pop();
		BFS(temp.x,temp.y);
	}
	
return 0;
}








