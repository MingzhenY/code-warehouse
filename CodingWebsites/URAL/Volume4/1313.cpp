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
{freopen("1313.txt","r",stdin); 
	while(cin>>N){
		For(i,N){
			For(j,N){
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d",a[0][0]);
		for(int I=1;I<N;I++){
			int i=I,j=0;
			while(i>=0) printf(" %d",a[i--][j++]);
		}
		for(int I=1;I<N;I++){
			int i=N-1,j=I;
			while(j<N) printf(" %d",a[i--][j++]);
		}
		cout<<endl;
	}
return 0;
}








