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

int a[1000000],b[1000000],c[1000000];
int N; 
int main(void)
{freopen("1048.txt","r",stdin); 
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d%d",&a[i],&b[i]);
		
	}
	int p=0;//½øÎ» 
	for(int i=N-1;i>=0;i--){
		c[i]=a[i]+b[i]+p;
		p=c[i]/10;
		c[i]%=10;
	}	
	for(int i=0;i<N;i++){
		printf("%c",c[i]+48);
	}
	cout<<endl;
return 0;
}








