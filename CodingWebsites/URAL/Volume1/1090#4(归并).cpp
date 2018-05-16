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
int merge(int a[],int lo,int hi){
	if(lo>=hi) return 0;
	int mid=lo+(hi-lo)/2,ANS=0;
	ANS+=merge(a,lo,mid);
	ANS+=merge(a,mid+1,hi);
	int *b=new int[mid-lo+1];
	int *c=new int[hi-mid];
	for(int i=0;i<mid-lo+1;i++) b[i]=a[lo+i];
	for(int i=0;i<hi-mid;i++) c[i]=a[i+mid+1];
	int Ib=0,Ic=0,Ia=0;
	while(Ia<hi-lo+1){
		if(Ib <mid-lo+1&&Ic < hi-mid){
			if(b[Ib]>c[Ic]) a[lo+Ia++]=c[Ic++],ANS+=mid-lo+1-Ib;
			else a[lo+Ia++]=b[Ib++];
		}
		else if(Ib <mid-lo+1){
			a[lo+Ia++]=b[Ib++];
		}
		else if(Ic<hi-mid){
			a[lo+Ia++]=c[Ic++];
		}
	}
	delete []b;
	delete []c;
	return ANS;
} 
int main(void)
{freopen("1090.txt","r",stdin); 
	while(cin>>N>>K){
		for(int i=0;i<K;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&R[i][j]);
			}
		}
		int ANS=merge(R[0],0,N-1);int ANSI=0;
		for(int i=0;i<K;i++){
			int D=merge(R[i],0,N-1);
			if(D >ANS) ANS=D,ANSI=i;
		}
		cout<<ANSI+1<<endl;
	}
return 0;
}








