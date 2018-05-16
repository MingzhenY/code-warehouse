#include <iostream>
#include <cstdio>
#include <cmath>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}
//四个方向：L0 U1 D2 R3
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
int n,m,k;
int maze[2000][2000]; 

int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>n>>m>>k){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				do scanf("%c",&maze[i][j]);while(maze[i][j]=='\n');
				//printf("%c",maze[i][j]);
			}
		}
		for(int j=0;j<m;j++){
			int ANS=0;
			for(int i=0;i<n;i++){
				for(int k=0;k<4;k++){
					int X=i+(i)*dx[k],Y=j+(i)*dy[k];
					if(X>=0&&X<n&&Y>=0&&Y<m){
						if(k==0&&maze[X][Y]=='R'||
						k==1&&maze[X][Y]=='D'||
						k==2&&maze[X][Y]=='U'||
						k==3&&maze[X][Y]=='L')
						ANS++;
					}
				}
			} 	
			if(j) printf(" ");
			printf("%d",ANS);
		}
		printf("\n");
	}
return 0;
}
