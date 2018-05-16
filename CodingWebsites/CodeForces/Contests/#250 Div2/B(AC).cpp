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


int sum,limit;

int lowbit(int x){
return x&(-x);
}
int a[17];
int b[17];
int low[100001];

int main(void)
{
	freopen("B.txt","r",stdin); 
	FOR(i,17) a[i-1]=0;
	while(cin>>sum>>limit){
		for(int i=1;i<=limit;i++){
			low[i]=lowbit(i);
			int t=i,count=0;
			while((t&1)==0) t>>=1,count++;
		//	OUT1(count);
			a[count]++;
		} 
		int t=sum;
		for(int i=0;i<17;i++) b[i]=sum&1,sum>>=1;
		
		int need=0;
		for(int i=16;i>=0;i--){
			if(b[i]+need<=a[i]){
				a[i]=b[i]+need;
				need=0;
				continue;
			}
			
			need=2*(b[i]+need-a[i]);
		}
	//	printf("B[i]: ");
	//	for(int i=0;i<17;i++) printf("%d ",a[i]);
	//	printf("\n");
		if(need>0){
			printf("-1\n");
			continue;
		} 
		int all=0;
		for(int i=0;i<17;i++){
			all+=a[i];
		}
		printf("%d\n",all);
		for(int i=1;i<=limit;i++){
			if(!all) break;
			int t=i,count=0;
			while((t&1)==0) t>>=1,count++;
			if(a[count]>0) {
				printf("%d",i),a[count]--,all--;
				if(all) printf(" ");
				else printf("\n");
			}
		}
		
		
	}
return 0;
}
