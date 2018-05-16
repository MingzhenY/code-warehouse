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
#define OUT4(a1,a2,a3,a4) cout out(a1) out(a2) out(a3) out(a4)<<endl
using namespace std;

int CB[630][4];
void PrepCB(){
	int cnt=0;
	for(int I1=0;I1<=6;++I1){
		for(int I2=I1+1;I2<=7;++I2){
			for(int I3=I2+1;I3<=8;++I3){
				for(int I4=I3+1;I4<=9;++I4){
					CB[cnt][0]=I1;
					CB[cnt][1]=I2;
					CB[cnt][2]=I3;
					CB[cnt][3]=I4;
					cnt++; 
					CB[cnt][0]=I1;
					CB[cnt][1]=I2;
					CB[cnt][2]=I4;
					CB[cnt][3]=I3;
					cnt++; 
					CB[cnt][0]=I1;
					CB[cnt][1]=I3;
					CB[cnt][2]=I2;
					CB[cnt][3]=I4;
					cnt++; 
				}
			}
		}
	}
}
int Count[10][10][10][10];
void AddCount(int a,int b,int c,int d){
	while(!(a<=b&&a<=c&&a<=d)){int t=a;a=b;b=c;c=d;d=t;}
	if(b > d) {b=b^d;d=b^d;b=b^d;}
	Count[a][b][c][d]++;
	return;
} 
int N; 
int main(void)
{freopen("1127.txt","r",stdin); 
	PrepCB();
	while(~scanf("%d",&N)){
		memset(Count,0,sizeof(Count));
		char color[7];
		for(int i=0;i<N;++i) {
			scanf("%s",color);
			for(int j=0;j<6;++j){
				switch(color[j]){
					case 'A':color[j]=0;break;
					case 'B':color[j]=1;break;
					case 'C':color[j]=2;break;
					case 'G':color[j]=3;break;
					case 'O':color[j]=4;break;
					case 'R':color[j]=5;break;
					case 'S':color[j]=6;break;
					case 'V':color[j]=7;break;
					case 'W':color[j]=8;break;
					case 'Y':color[j]=9;break;
				}
			}
			AddCount(color[0],color[1],color[3],color[2]);
			AddCount(color[0],color[5],color[3],color[4]);
			AddCount(color[1],color[5],color[2],color[4]);
		}
		int ANS=0;
		for(int i=0;i<630;++i){
			if(Count[CB[i][0]][CB[i][1]][CB[i][2]][CB[i][3]]>ANS) ANS=Count[CB[i][0]][CB[i][1]][CB[i][2]][CB[i][3]];
		}
		printf("%d\n",ANS);
	}
	
return 0;
}








