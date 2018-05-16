#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
template <class T>
T Min(T a,T b) {
	return a<b?a:b;
}
bool zrt[245][60001];
unsigned char num[245][60001];
int main(void)
{freopen("1073.txt","r",stdin); 
	int N;
	while(cin>>N){
			memset(zrt,0,sizeof(zrt));
		memset(num,0,sizeof(num));
		int K=1;
		while(K*K<N) K++;
		if(K*K==N) {
			num[K-1][N]=1;goto end;
		}
		zrt[0][0]=1; 
		for(int i=1;i<K;i++){
			for(int j=0;j<=N;j++){ 
				if(j-i*i>=0&&zrt[i-1][j-i*i]) { 
					if(zrt[i-1][j]){
						zrt[i][j]=1;num[i][j]=Min((unsigned char)(num[i-1][j-i*i]+1),num[i-1][j]);
					}
					else zrt[i][j]=1,num[i][j]=num[i-1][j-i*i]+1;
				} 
				else if(zrt[i-1][j]) {
					zrt[i][j]=1,num[i][j]=num[i-1][j];continue;
				}
			}
		}
		//for(int i=1;i<90;i++) OUT3(i,zrt[3][i],num[3][i]);
		
		//int ANS=inf;
		//for(int i=0;i<=60000;i++){
		//	if(zrt[K-1][i]&&num[K-1][i]&&num[K-1][i]<ANS) ANS=num[K-1][i];
		//}
		end:
		cout<<(int )num[K-1][N]<<endl;
	}
	

	
return 0;
}








