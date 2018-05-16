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

double g[401][101];
void Init(){
	for(int i=0;i<=100;++i) g[2][i]=1;
	for(int n=3;n<=400;++n){
		for(int k=0;k<=n;++k){
			g[n][k]=1.0;
			for(int t=2;t<n;++t){
				g[n][k]+=k*(g[t][k]*g[n-t+1][k]-g[t][k-1]*g[n-t+1][k-1]);
			}
		}
	}
} 
int n;
int main(void)
{//freopen("1776.txt","r",stdin); 
	Init();
	while(cin>>n){
		double ANS=0;
		for(int i=1;i<=100;++i){
			ANS+=i*(g[n][i]-g[n][i-1]);
		}
		cout<<ANS<<endl;
	}
return 0;
}








