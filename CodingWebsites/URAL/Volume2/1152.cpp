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

int N;
int a[50],All;
int A[1048576];
int mask[20];
int bit[31],MSK;
void showMask(int k){
	for(int i=0;i<N;++i,k>>=1) printf("%d",k&1);
	printf("\n");
}
void Init(){
	bit[0]=1;All=0;
	for(int i=1;i<31;++i) bit[i]=bit[i-1]<<1;
	mask[0]=7;MSK=(1<<N)-1;
	for(int i=1;i<N;++i){
		mask[i]=(mask[i-1]<<1)&MSK;
		if(mask[i-1]&bit[N-1]) mask[i]|=1;
	}
	memset(A,-1,sizeof(A));
	A[0]=0;
}
int F(int k,int Sum){
	if(~A[k]) return A[k];
	if(Sum==0) return A[k]=0;
	int Min=-1;
	for(int i=0;i<N;++i){
		int I1=i,I2=(i+1)%N,I3=(i+2)%N;
		if(!(k&mask[i])) continue;
		int DelSum=0;
		if (k&bit[I1]) DelSum+=a[I1];
		if (k&bit[I2]) DelSum+=a[I2];
		if (k&bit[I3]) DelSum+=a[I3];
		int ANS=Sum-DelSum+F(k&(~mask[i]),Sum-DelSum);
		if(!~Min||ANS <Min){
			Min=ANS;
		}
	}
	return A[k]=Min;
}
int main(void)
{freopen("1152.txt","r",stdin); 
	scanf("%d",&N);
	Init();
	for(int i=0;i<N;++i) scanf("%d",&a[i]),All+=a[i];
	printf("%d\n",F(MSK,All));
return 0;
}








