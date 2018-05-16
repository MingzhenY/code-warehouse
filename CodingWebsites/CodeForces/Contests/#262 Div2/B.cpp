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


int ans[10000];int N;

long long a,b,c;int Sum;
void dfs(int k,int left,int sumleft){
	long long D=k;long long SumD=1;
	for(int i=0;i<a;i++) SumD*=Sum;
	for(int i=0;i<left;i++) D*=10;
	if(D> b*SumD+c) return; 
	if(!left){
		if(!sumleft){
			if((k-c)%b!=0) return;
			long long D=1;
			for(int i=0;i<a;i++) D*=Sum;
			if(D==((k-c)/b)){
				ans[N++]=k;
			}
		}
		return ;
	}
	for(int j=0;j<10;j++){
		if(sumleft>=j) dfs(10*k+j,left-1,sumleft-j);
	}
}
int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>a>>b>>c){
		N=0;
		for(Sum=1;Sum<=81;Sum++){
			long long D=1;
			//OUT1(Sum);
			for(int i=0;i<a;i++) D*=Sum;
			if(D*b>=1000000000) break;
			dfs(0,9,Sum);
		}
		sort(ans,ans+N);
		
		cout<<N<<endl;
		for(int i=0;i<N;i++) {
			printf("%d",ans[i]);
			if(i==N-1)printf("\n");
			else printf(" ");
		}
	}
return 0;
}
