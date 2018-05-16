#include <iostream> 
#include <cstdio>
#include <cmath>
#include <cstring>
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



char a[4][112]; 
int n[4];
int ANS=-1;

int main(void)
{
	freopen("A.txt","r",stdin); 
	for(int i=0;i<4;i++) scanf("%s",a[i]);
	for(int i=0;i<4;i++) n[i]=strlen(a[i])-2;
//	for(int i=0;i<4;i++) OUT1(n[i]);
	int WRONG=0;
	for(int i=0;i<4;i++){
		int T=1;
		for(int j=0;j<4;j++){//是否小于 
			if(j==i) continue;
			if(n[i]*2>n[j]) T=0;
		}
		if(T) {
			if(ANS==-1) ANS=i;
			else WRONG=1;
			
		}
		//OUT2(T,WRONG);
		T=1;
		for(int j=0;j<4;j++){//是否大于 
			if(j==i) continue;
			if(n[i]<n[j]*2) T=0;
		}
		if(T) {
			if(ANS==-1) ANS=i;
			else WRONG=1;
			
		}
	//	OUT2(T,WRONG);
	}
	
	if(ANS==-1||WRONG) cout<<"C"<<endl;
	else cout<<(char)(ANS+'A')<<endl;
	
	
	
return 0;
}














