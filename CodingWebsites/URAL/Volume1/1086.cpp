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

int N;
int p[500000];
int b[100000];
int main(void)
{freopen("1086.txt","r",stdin); 
	for(int i=2;i<500000;i++){
		if(p[i]) continue;
		for(int j=i;j<500000;j+=i) p[j]=i;
	}
	//For(i,100) OUT2(i,p[i]);
	int Cur=1;
	for(int i=2;i<500000&&Cur<=15000;i++){
		if(p[i]==i) b[Cur++]=i;
	}
	cin>>N;
	int a;
	For(i,N){
		scanf("%d",&a);
		cout<<b[a]<<endl;
	}
return 0;
}








