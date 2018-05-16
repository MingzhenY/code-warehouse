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

int FS[1001][1001];//FS[i][j]-FS[i][j-1]表示 i个鹰蛋，j次尝试可以确定的最大楼层。
int main(void)
{freopen("1223.txt","r",stdin); 
	for(int j=0;j<=1000;j++) FS[1][j]=j*(j+1)/2,FS[j][0]=0,FS[j][1]=1;
	for(int i=2;i<=1000;i++){
		for(int j=2;j<=1000;j++){
			FS[i][j]=FS[i][j-1]+FS[i-1][j-1]+j;
			if(FS[i][j]-FS[i][j-1]>=2000) break;
		}
	}
	int N,E;
	while(cin>>E>>N&&(E||N)){
		int ANS;
		for(int j=1;j<=1000;j++){//可以二分，但是懒得二分了。 
			if(FS[E][j]-FS[E][j-1]>=N) {
				ANS=j;break;
			}
		}
		cout<<ANS<<endl;
	}
return 0;
}








