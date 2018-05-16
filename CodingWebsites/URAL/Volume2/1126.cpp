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

int a[25000];int N;
int ha[200];
int M;
int MAX(int L,int R){
	int ANS=0;
	for(int i=L/500+1;i<=R/500-1;i++){
		ANS=max(ANS,ha[i]);//OUT1(1);
	}
	for(int i=L;i<min(L/500*500+500,R);i++) {
		ANS=max(ANS,a[i]);//OUT1(2);
	}
	for(int i=max(R/500*500,L);i<=R;i++) {
		ANS=max(ANS,a[i]);//OUT1(3);
	}
	return ANS;
}
int main(void)
{freopen("1126.txt","r",stdin); 
	cin>>M;
	int temp;N=0;
	memset(ha,0,sizeof(ha));
	while(cin>>temp){
		if(!~temp) break;
		a[N++]=temp;
		ha[N/500]=max(ha[N/500],temp);
	}
	for(int i=0;i<=N-M;i++){
		printf("%d\n",MAX(i,i+M-1));
	}
return 0;
}








