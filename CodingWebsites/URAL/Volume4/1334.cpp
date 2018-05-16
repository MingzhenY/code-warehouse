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

int chess[8][8];
int X[32],Y[32],v[32]; //1±íÊ¾°×É« 
int dx[8]={1,1,-1,-1,-1,0,1,0};
int dy[8]={1,-1,1,-1,0,1,0,-1};
bool check(int x,int y){
	for(int i=0;i<8;i++){
		int Dx=x+dx[i],Dy=y+dy[i];
		if(Dx>=0&&Dx<8&&Dy>=0&&Dy<8){
			if(~chess[Dx][Dy]){
				if(chess[Dx][Dy]+chess[x][y]==1){
					int Tx=x+2*dx[i],Ty=y+2*dy[i];
					if(Tx>=0&&Tx<8&&Ty>=0&&Ty<8&&!~chess[Tx][Ty]){
						return 1;
					}
					Tx=x-dx[i],Ty=y-dy[i];
					if(Tx>=0&&Tx<8&&Ty>=0&&Ty<8&&!~chess[Tx][Ty]){
						return 1;
					}
				}
			}
		}
	}
	/*
	OUT2(x,y);
	For(i,8){
		For(j,8){
			printf("%d ",chess[i][j]);
		}cout<<endl;
	}*/
	return 0;
} 
int main(void)
{freopen("1334.txt","r",stdin); 
	For(i,32){
		string str;
		cin>>str;
		X[i]=str[0]-'a';
		Y[i]=str[1]-'1';
		v[i]=i&1;
	}
	memset(chess,-1,sizeof(chess));
	int T=0;
	For(i,32){
		chess[X[i]][Y[i]]=v[i];
		++T;
		if(check(X[i],Y[i])) {
			printf("%d\n",T);
			return 0;
		}
	}
	printf("Draw\n");
	
return 0;
}








