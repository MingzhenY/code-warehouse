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




int t;
int n,k,d1,d2;int a[3];
bool F();
int main(void)
{
	freopen("C.txt","r",stdin); 
	cin>>t;
	int T;
	for(int i=0;i<t;i++){
		T=0;
		
		scanf("%d%d%d%d",&n,&k,&d1,&d2);
		a[2]=k-d1-2*d2;
		if((a3<0)||(a3>0)&&(a3%3));
		else{
			a2
		}
		/*
		
		 T=0;
		else if(n-k<d1+2*d2) T=0;
		else {
			int b=n-k-2*d1-d2;
			if(b<0||(b>0)&&(b%3)) T=0;
			else T=1;
		}
		*/
	
	if(T) printf("yes\n");
	else printf("no\n");
	}
return 0;
}
bool F(){
	int b[3];
	for(int i=0;i<3;i++) b[i]=a[i];
	sort(b,b+3);
	int D=n-k;D=D-(b[2]-b[0]+b[1]-b[0]);
	if(D<0||((D>0)&&(D%3))){
		return 0;
	}
	else return 1;
}













