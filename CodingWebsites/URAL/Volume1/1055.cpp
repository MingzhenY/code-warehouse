#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
#define  inf  0x5fffffff
#define TIMEFOR(x)  clock_t start_##x = clock();  x();clock_t end_##x = clock();            \
cout <<"Time For " <<#x<<":  "<<(double)(end_##x-start_##x)/CLOCKS_PER_SEC<<" seconds" <<endl;
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int p[1000000];
int rp[100000]; int np;
int num[10000];
int N,M;
void F(int N,int M);
void f(int N,int t);
void cal(){
	memset(p,0,sizeof(p));
	np=0;
	for(int i=2;i<1000000;i++){
		if(p[i]) continue;
		rp[np++]=i;
		for(int j=i;j<1000000;j+=i){
			p[j]=i;
		}
	}
}
int main(void)
{freopen("1055.txt","r",stdin); 
	TIMEFOR(cal);
	
	
	while(cin>>N>>M){
		memset(num,0,sizeof(num));
		F(N,M);int ANS=0;
		for(int i=0;rp[i]<=N;i++){
			ANS+=num[i]>0;
		}
		
		cout<<ANS<<endl;
	}
return 0;
}
void F(int N,int M){
	f(N,1);
	f(M,-1);
	f(N-M,-1);
}
void f(int N,int t){
	for(int i=0;rp[i]<=N;i++){
		int temp=N;
		while(temp) num[i]+=t*temp/rp[i],temp/=rp[i];
	}
}







