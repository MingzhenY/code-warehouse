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





int n;
int a[100001];
int b[100001];
bool check(int i,int j);
int main(void)
{
//	n=10;
	//check(3,7);
//	return 0;
	freopen("B.txt","r",stdin); 
	
	while(cin>>n){
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int T=check(1,1);
		int t1=-1;
		for(int i=1;i<=n;i++){
			if(a[i+1]<a[i]) {
				t1=i;break;
			}
		}
		
		int t2=-1;
		for(int i=n;i>0;i--){
			if(a[i-1]>a[i]) {
				t2=i;break;
			}
		}
		
		if(t1<t2&&(check(1,t1)||check(t1,t2)||check(t2,n))) {
			printf("yes\n%d %d\n",t1,t2);
		}
		else{
			if(T){
				printf("yes\n1 1\n");
			}
			else {
				printf("no\n");
			}
			
		}
		
	}
return 0;
}
bool check(int i,int j){
	
	if(i<j){
		for(int k=1;k<=n;k++){
			if(k>=i&&k<=j){
				b[k]=a[(j+i-k)];
			}
			else b[k]=a[k];
		}
	} 
	else {
		for(int k=1;k<=n;k++) b[k]=a[k];
	}
	int T=1;
	for(int k=1;k<n;k++){
		if(b[k+1]<b[k]) T=0;
	}
	//cout<<endl;
	return T;
}
