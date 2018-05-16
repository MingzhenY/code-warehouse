#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int r,c,n,k,x,y;
char D[11][11];
int A[11][11];
int main(void)
{
	freopen("635A.txt","r",stdin); 
	while(cin>>r>>c>>n>>k){
		memset(D,0,sizeof(D));
		memset(A,0,sizeof(A));
		for(int i=0;i<n;++i){
			cin>>x>>y;
			D[x][y]=1;
		}
		/*
		printf("Show Grid:\n");
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				printf("%d ",D[i][j]);
			}
			printf("\n");
		}
		printf("End Grid");*/
		
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				A[i][j]=D[i][j]+A[i-1][j]+A[i][j-1]-A[i-1][j-1];
			}
		}
		/* printf("Show A:\n");
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}
		printf("End A"); */
		
		int ANS=0;
		for(int i=1;i<=r;++i){
			for(int j=1;j<=c;++j){
				if(A[i][j]<k) continue;
				for(int x=0;x < i;++x){
					for(int y=0;y < j;++y){
						ANS+= (A[i][j]-A[x][j]-A[i][y]+A[x][y])>=k;
					}
				}
			}
		}
		cout<<ANS<<endl;
	}
return 0;
}














