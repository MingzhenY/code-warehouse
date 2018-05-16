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

int R[20][10000];
int N,K;
int rank[10000];
int main(void)
{freopen("1090.txt","r",stdin); 
	while(cin>>N>>K){
		
		for(int i=0;i<K;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&R[i][j]);
			}
		}
		int ALL=-1,ANS=1; 
		for(int i=0;i<K;i++){
			int tempA=0;
			for(int j=0;j<N;j++){
				rank[j]=0;
				for(int k=j-1;k>=0;k--){
					if(R[i][k]>R[i][j]) {
						rank[j]=rank[k]+1;
						break;
					}
				}
				tempA+=rank[j];
			}
			OUT2(i,tempA);
			if(~ALL) {
				if(ALL<tempA) ALL=tempA,ANS=i+1;
			}
			else ALL=tempA,ANS=i+1;
		}
		cout<<ANS<<endl;
	}
return 0;
}








