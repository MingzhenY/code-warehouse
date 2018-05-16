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
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}




int n,d;
int a[100];

int main(void)
{
	freopen("A.txt","r",stdin); 
	
	while(cin>>n>>d){
		int time=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);time+=a[i];
		}
		time+=(n-1)*10;
		if(time>d) printf("-1\n");
		else printf("%d\n",2*(n-1)+(d-time)/5);
	}
return 0;
}














