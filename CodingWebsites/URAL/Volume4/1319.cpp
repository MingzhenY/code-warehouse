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

int a[100][100];
int N;
int main(void)
{freopen("1319.txt","r",stdin); 
	while(cin>>N){
		int T=1;
		for(int I=N-1;I>=0;I--){
			int i=0,j=I;
			while(j<N) a[i++][j++]=T++;
		}
		for(int I=1;I<N;I++){
			int i=I,j=0;
			while(i<N) a[i++][j++]=T++;
		}
		For(i,N){
			For(j,N){
				if(j) printf(" ");
				printf("%d",a[i][j]);
			}cout<<endl;
		}
	}
return 0;
}








