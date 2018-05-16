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

int D[11][11];
int ANS[11];
int main(void)
{freopen("1142.txt","r",stdin); 
	memset(D,0,sizeof(D));
	D[2][1]=1;D[2][2]=2;
	for(int i=3;i<=10;i++){
		for(int j=1;j<=i;j++){
			D[i][j]=j*D[i-1][j]+j*D[i-1][j-1];
		}
	}
	for(int i=0;i<11;i++){
		ANS[i]=0;
		for(int j=1;j<=i;j++) ANS[i]+=D[i][j];
	}
	
	int a;
	while(cin>>a){
		if(~a){
			cout<<ANS[a]<<endl;
		}
		else break;
	}
return 0;
}








