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

long long ANS[37];
int main(void)
{
freopen("1044.txt","r",stdin); 
	int N;
	while(cin>>N){
	
	memset(ANS,0,sizeof(ANS));

	N/=2;
	int D=1;
	for(int i=1;i<N;i++) D*=10;
	//OUT1(D);
	for(int i=0;i<10*D;i++){
		int a=i;int t=0;
		for(int j=0;j<4;j++){
			t+=a%10;a/=10;
		}
		ANS[t]++;
	}
	
	long long A=0;
	for(int i=0;i<37;i++) A+=ANS[i]*ANS[i];
	cout<<A<<endl;
	}
return 0;
}








