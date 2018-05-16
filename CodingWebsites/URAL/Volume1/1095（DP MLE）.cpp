#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,n;
int rem[20];
int d[20];//20¸öÊý×Ö 
bool dp[21][1<<20][7];
int path[21][1<<20][7];
char alp[21][1<<20][7];
char r[21][1<<20][7];
int main(void)
{freopen("1095.txt","r",stdin); 
	OUT1(sizeof(path)/1048576.0); 
	rem[0]=1;
	for(int i=1;i<20;++i) rem[i]=(rem[i-1]*10)%7;
	cin>>N;
	for(int kkk=0;kkk<N;++kkk){
		int a;scanf("%d",&a);
		memset(d,0,sizeof(d));
		n=0;while(a){d[n++]=a%10;a/=10;}
		//for(int i=0;i<n;++i) printf("d[%d]=%d\n",i,rem[i]);
		memset(dp,0,sizeof(dp));
		memset(alp,0,sizeof(dp));
		memset(path,0,sizeof(path));
		dp[0][0][0]=1;int J=1<<n;
		for(int i=0;i<n;++i){
			for(int j=0;j<J;++j){
				for(int k=0;k<7;++k){
					if(dp[i][j][k]){
						int mark=j;int m=1;
						for(int t=0;t<n;++t) {
							if(~j&m){
								int nI=i+1,nJ=j|m,nK=(k+rem[i]*d[t])%7;
								//if(nI==1) OUT3(nI,nJ,nK),OUT3(1,j,d[t]);
								dp[nI][nJ][nK]=1;
								path[nI][nJ][nK]=j;
								alp[nI][nJ][nK]=d[t];
								r[nI][nJ][nK]=k;
							}
							mark>>=1;m <<=1;
						}
					}
				}
			}
		}
		//OUT3(n,J-1,0);
		//OUT1(dp[n][J-1][0]);
		if(dp[n][J-1][0]){
			int x=n,y=J-1,t=0;
			while(x>0){
				int nx=x,ny=y,nt=t;
				//OUT3(x,y,t);
				//OUT3(dp[x][y][t],(int)alp[x][y][t],path[x][y][t]);
				printf("%c",alp[nx][ny][nt]+48);
				y=path[nx][ny][nt];
				t=r[nx][ny][nt];
				x--;
			}
			printf("\n");
		}
		else{
			printf("0\n");
		}
	}
return 0;
}








