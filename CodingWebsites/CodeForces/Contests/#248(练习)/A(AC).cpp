#include <iostream>
#include <cstdio>
#include <cmath>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}

int n;
int a[100];
int main(void)
{
	freopen("A.txt","r",stdin); 
	
	while(cin>>n){
		int e1=0,e2=0;
		
		FOR(i,n) {
			scanf("%d",&a[i-1]);
			if(a[i-1]==100) e1++; 
			else e2++;
		}
		int T=-1;
		
		if(e2&1){
			if((e1&1)==0&&e1>1) T=1;
			else T=0;
		}
		else{
			if(e1&1) T=0;
			else T=1;
		}
		if(T) printf("YES\n");
		else printf("NO\n");		
	}
return 0;
}








