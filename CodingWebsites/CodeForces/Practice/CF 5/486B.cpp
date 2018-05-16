#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool A[101][101];
bool B[101][101];

int n,m;
bool H(int k){bool ANS=0;for(int j=0;j<n;++j)ANS=ANS||A[k][j];return ANS;}
bool L(int k){bool ANS=0;for(int i=0;i<m;++i) ANS=ANS||A[i][k];return ANS;}
void setH(int k){for(int j=0;j<n;++j) A[k][j]=false;}
void setL(int k){for(int i=0;i<m;++i) A[i][k]=false;}

int main(void)
{
	freopen("486B.txt","r",stdin); 
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			A[i][j]=true;
	
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&B[i][j]);
			if(!B[i][j]){setH(i);setL(j);}
		}
	}
	
	bool T=1;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			//printf("(%d,%d): H(i)||L(j)=%d B[i][j]=%d\n",i,j,H(i)||L(j),B[i][j]);
			if((H(i)||L(j))!=B[i][j])  T=false;
		}
	}
	if(T){
		printf("YES\n");
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				printf("%d",A[i][j]);
				if(j==n-1) printf("\n");
				else printf(" ");
			}
		}
	}
	else printf("NO\n");
	

		
return 0;
}














