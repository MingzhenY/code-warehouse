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




int n,a[3001],b[3001],m;
int bx[3001],by[3001];

int main(void)
{
	freopen("D.txt","r",stdin); 
	while(cin>>n){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);b[i]=a[i];
		}
		cin>>m;
		int A=0;
		for(int i=1;i<=n;i++){
			if(b[i]==i) continue;
			
			for(int j=i+1;j<=n;j++){
				if(b[j]==i) A++;
				if(b[j]==i&&b[i]==j) A+=2;
				int t=b[i];b[i]=b[j];b[j]=t;
			}
		}
		
		if(A==m) {
			cout<<"0"<<endl;
			continue;
		}
		
		int ANS=0;
		if(A>m){
			for(int i=1;i<=n;i++){
				if(a[i]==i) continue;
				for(int j=i+1;j<=n;j++){
					if(A==m) break;
					if(A-m>=2&&a[i]==j&&a[j]==i) {
						A-=2;bx[ANS]=i;by[ANS]=j;ANS++;continue;
					}
					if(A-m>=1&&a[i]!=j&&a[j]==i){
						A-=1;bx[ANS]=i;by[ANS]=j;ANS++;continue;
					}
				}
				if(A==m) break;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]!=i) continue;
				for(int j=i+1;j<=n;j++){
					if(m-A>=2&&a[j]==j) {
						A+=2;bx[ANS]=i;by[ANS]=j;ANS++;continue;
					}
					if(m-A>=1&&a[j]!=j){
						A+=1;bx[ANS]=i;by[ANS]=j;ANS++;continue;
					}
					if(A==m) break;
				}
				if(A==m) break;
			}
		}
		
		cout<<ANS<<endl;
		printf("%d %d",bx[0],by[0]);
		for(int i=1;i<ANS;i++){
			printf(" %d %d",bx[i],by[i]);
		}
		cout<<endl;
		
		
		
		
		
		
		
		
	}

return 0;
}














