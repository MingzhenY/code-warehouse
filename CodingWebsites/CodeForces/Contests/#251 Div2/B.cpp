#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
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



int n,x;
int c[100000];


int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>n>>x){
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
		}
		sort(c,c+n);
		long long ANS=0;
		for(int i=0;i<n;i++){
			ANS+=(long long) c[i]*x;
			if(x>1) x--;
		}
		cout<<ANS<<endl;
		
		
	}
return 0;
}
