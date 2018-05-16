#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int x,y;
int xink[30],xinkn;
int yink[30],yinkn;
bool F(int k){//k>=2
	if(k<2) return false;
	int t;
	//x,y
	t=x;xinkn=0;while(t) xink[xinkn++]=t%k,t/=k;
	t=y;yinkn=0;while(t) yink[yinkn++]=t%k,t/=k;
	//OUT1(k);
	//printf("x: ");
	//for(int i=xinkn-1;i>=0;--i) printf("%d",xink[i]);
	//printf("y: ");
	//for(int i=yinkn-1;i>=0;--i) printf("%d",yink[i]);
	//
	//OUT2(xinkn,yinkn);
	t=0;int j;
	for(j=0;j<yinkn;++j,++t){
		while(t <xinkn&& xink[t]!=yink[j]) t++;
		if(t>=xinkn) break; 
	}
	//OUT2(j,t);
	if(j==yinkn) return true;
	return false;
}
int work[1000007];
int main(void)
{
	freopen("1071.txt","r",stdin); 
	while(cin>>x>>y){
		memset(work,-1,sizeof(work));
		int ANS=0;
		for(long long i=2;i <=1000000;++i){
			if(~work[i]) continue;
			if(F(i)){ANS=i;break;}
			else{
				for(long long j=i*i;j<=1000000;j*=i){
					work[j]=0;
				}
			}
		}
		if(ANS) printf("%d\n",ANS);
		else printf("No solution\n");
	}
return 0;
}













