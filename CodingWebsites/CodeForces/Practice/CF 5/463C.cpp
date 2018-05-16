#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int matrix[2000][2000];
int n;
long long MainSum[4000];
long long SubSum[4000];
bool visMain[4000];
bool visSub[4000];
struct A{
	int x,y;
	long long ANS;
	bool operator <(const A&B)const{
		return ANS >B.ANS;
	}
}D[4000000];
int main(void)
{
	freopen("463C.txt","r",stdin); 
	while(~scanf("%d",&n)){
		int N=n<<1;
		for(int i=0;i<N;i++) MainSum[i]=SubSum[i]=0LL,visMain[i]=visSub[i]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
				MainSum[i-j+n]+=matrix[i][j];
				SubSum[i+j]+=matrix[i][j];
				//printf("%2d ",i+j);
			}//cout<<endl;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int X=i*n+j;
				D[X].x=i;D[X].y=j;
				D[X].ANS=MainSum[i-j+n]+SubSum[i+j]-matrix[i][j];
			}
		}
		sort(D,D+n*n);
		N=n*n;int ANS=-1;
		for(int i=1;i<N;i++){
			int x=D[i].x,y=D[i].y;
			if(((D[0].x-D[0].y+n)&1)+((x-y+n)&1)==1){
				if( ((D[0].x+D[0].y)&1)+((x+y)&1)==1 ){
					ANS=i;break;
				}
			}
		}
		if(~ANS){
			printf("%I64d\n",D[0].ANS+D[ANS].ANS);
			printf("%d %d %d %d\n",D[0].x+1,D[0].y+1,D[ANS].x+1,D[ANS].y+1);
		}
		
		
	} 

		
return 0;
}














