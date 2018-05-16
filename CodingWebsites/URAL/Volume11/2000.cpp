#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int a[100000];
int n; 
int x,y;
int sum(int L,int R){
	int ANS=0;
	if(L <0) L=0;
	if(R>=n) R=n-1;
	if(L>R) return 0;
	for(int i=L;i<=R;++i){
		ANS+=a[i];
	} 
	return ANS;
}
int main(void)
{freopen("2000.txt","r",stdin); 
	while(cin>>n){
		int S=0;
		for(int i=0;i<n;++i) scanf("%d",&a[i]),S+=a[i];
		scanf("%d%d",&x,&y);x--;y--;
		int t1,t2;
		if(x==y){
			t1=sum(0,x);
			t2=sum(x,n-1);
			if(t1>t2){
				printf("%d %d\n",sum(0,x),S-sum(0,x));
			}
			else{
				printf("%d %d\n",sum(x,n-1),S-sum(x,n-1));
			}
		}
		else{
			if(x <y){
				printf("%d %d\n",sum(0,(x+y)>>1),S-sum(0,(x+y)>>1));
			}
			else{
				if((x+y)&1) printf("%d %d\n",sum((x+y)>>1,n-1),S-sum((x+y)>>1,n-1));
				else printf("%d %d\n",sum((x+y)>>1,n-1),S-sum((x+y)>>1,n-1));
			}
		}
	}
	
	
	
	
return 0;
}








