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

int N;
int a[101][101];
int sum[101][101];
int M[101][101];
int main(void)
{freopen("1146.txt","r",stdin); 
	
	while(cin>>N){
		memset(a,0,sizeof(a));
		FOR(i,N){
			FOR(j,N){
				scanf("%d",&a[i][j]);
			}
		}
		FOR(i,N){
			FOR(j,N){
				sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
				//printf("%d ",sum[i][j]);
			}//cout<<endl;
		}
		FOR(i,N){
			FOR(j,N){
				M[i][j]=-1;
				FOR(k,i){
					FOR(s,j){
						if(~M[i][j]) M[i][j]=max(M[i][j],sum[i][j]-sum[i-k][j]-sum[i][j-s]+sum[i-k][j-s]);
						else M[i][j]=sum[i][j]-sum[i-k][j]-sum[i][j-s]+sum[i-k][j-s];
					}
				}
			}
		} 
		int ANS=M[1][1];
		FOR(i,N){
			FOR(j,N){
				ANS=max(ANS,M[i][j]);
			}
		}
		cout<<ANS<<endl;	
	}
	
return 0;
}








