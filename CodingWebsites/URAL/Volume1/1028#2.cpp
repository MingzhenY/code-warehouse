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

struct STAR{
	int x,y;
	int level;
	bool operator <(const STAR &B)const{
		return x<=B.x&&y<=B.y; 
	}
}star[15000];
int num[15000];

int x[32001];
int Ix[161];//32000=160*200 
int main(void)
{freopen("1028.txt","r",stdin); 
	int N;cin>>N;
	memset(x,0,sizeof(x));memset(Ix,0,sizeof(Ix));
	for(int i=0;i<N;i++){
		star[i].level=0;num[i]=0;
		scanf("%d%d",&star[i].x,&star[i].y);

		for(int j=0;j<star[i].x/200;j++){
			star[i].level+=Ix[j];
		}		
		for(int j=star[i].x/200*200;j<=star[i].x;j++){
			star[i].level+=x[j];
		}
		x[star[i].x]++;Ix[star[i].x/200]++;
	}
	for(int i=0;i<N;i++){
		//OUT2(i,star[i].level);
		num[star[i].level]++;
	}
	for(int i=0;i<N;i++){
		printf("%d\n",num[i]);
	}
	
	
return 0;
}








