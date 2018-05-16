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

char a[4][4];int ALL=0;
int dx[5]={-1,0,1,0,0};
int dy[5]={0,-1,0,1,0};
int main(void)
{freopen("1060.txt","r",stdin); 
	ALL=0;
	for(int i=0;i<16;i++){
		scanf(" %c",&a[i/4][i%4]);
		 ALL+=a[i/4][i%4]=a[i/4][i%4]=='b';
	}
	 /* 
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d",a[i][j]);
		}
		cout<<endl;
	}   */ 
	int ANS=-1;
	for(int i=0;i<(1<<16);i++){
		//if(i!=83) continue;
		char b[4][4];
		memcpy(b,a,sizeof(a));
		int tempA=ALL;int move=0; 
		for(int j=0;j<16;j++) {
			if((i>>j)&1){move++;
				//OUT2(j/4,j%4);
				for(int k=0;k<5;k++){
					int nx=j/4+dx[k],ny=j%4+dy[k];
					if(nx>=0&&nx<4&&ny>=0&&ny<4){
						tempA+=1-b[nx][ny]*2;
						b[nx][ny]=1-b[nx][ny];
						//OUT3(nx,ny,b[nx][ny]);
					}
				}
				//OUT1(tempA);
			}
		}
		if(tempA==0||tempA==16){//³É¹¦ 
			if(~ANS){
				if(ANS>move) {
					ANS=move;//OUT3(i,move,tempA);
				}
			}
			else {
				ANS=move;//OUT3(i,move,tempA);
			}
		}
	} 
	if(~ANS){
		printf("%d\n",ANS);
	}
	else{
		printf("Impossible\n");
	}
	
	
return 0;
}








