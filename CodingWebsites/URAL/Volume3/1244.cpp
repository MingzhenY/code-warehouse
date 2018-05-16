#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
struct Mark{//¼ÇÂ¼Â·¾¶ 
	unsigned long long M[2];
	Mark(){M[0]=M[1]=0;}
	void init(){M[0]=M[1]=0;}
	void set(int k){
		M[k/64]|=1ll<<(k%64);
	}
	bool is(int k){
		return ((M[k/64]>>(k%64))&1ll);
	}
};
int dp[2][100001]; 
Mark path[2][100001];
int a[100];int Part,Sum,N;
int main(void)
{freopen("1244.txt","r",stdin); 
	while(cin>>Part>>N){
		Sum=0;
		For(i,N){
			scanf("%d",&a[i]);Sum+=a[i];
		}
		memset(dp,0,sizeof(dp));
		For(i,2)For(j,100001)path[i][j].init();
		dp[0][a[0]]=1;dp[0][0]=1;
		path[0][a[0]].set(0);
		for(int i=1;i<N;i++){
			for(int j=0;j<=100000;j++){
				dp[i&1][j]=0;
				if(dp[(i+1)&1][j]){
					dp[i&1][j]+=dp[(i+1)&1][j];
					path[i&1][j]=path[(i+1)&1][j];
				}
				if(j-a[i]>=0&&dp[(i+1)&1][j-a[i]]){
					dp[i&1][j]+=dp[(i+1)&1][j-a[i]];
					path[i&1][j]=path[(i+1)&1][j-a[i]];
					path[i&1][j].set(i);
				}
				
			}
		}
		int ANS=dp[(N+1)&1][Sum-Part];int first=0;
		switch(ANS){
			case 0:printf("0\n");break;
			case 1:
				for(int i=0;i<N;i++){
					if(path[(N+1)&1][Sum-Part].is(i)) {
						if(first) printf(" ");
						printf("%d",i+1);first++;
					}
				}cout<<endl;
				break;
			default:printf("-1\n");break;
		}
	}
return 0;
}








