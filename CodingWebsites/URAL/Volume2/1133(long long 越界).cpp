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
struct A{
	long long a[2][2];
	A operator*(const A&B)const{
		A C;
		For(i,2){
			For(j,2){
				C.a[i][j]=0;
				For(k,2){
					C.a[i][j]+=a[i][k]*B.a[k][j];
				}
			}
		}
		return C;
	}
	A power(int i){
		A C;
		if(!i){
			C.a[0][0]=C.a[1][1]=1;
			C.a[0][1]=C.a[1][0]=0;
			return C;
		}
		if(i==1) return *this;
		if(i==2) return *this**this;
		if(i&1){
			return *this*power(i>>1).power(2);
		}
		else{
			return power(i>>1).power(2);
		}
	}
};

long long i,Fi,j,Fj,N;
int main(void)
{freopen("1133.txt","r",stdin); 
	while(cin>>i>>Fi>>j>>Fj>>N){
		if(i>j){
			long long t=i;i=j;j=t;
			t=Fi;Fi=Fj;	Fj=t;
		}
		A L,R;
		For(x,2){
			For(y,2){
				R.a[x][y]=(x+y)>0;
			}
		}
		for(int k=50;k<100;k++) OUT2(k,R.power(k).a[0][0]);
		L=R.power(j-i);
		if(j!=i+1){
			Fj=(Fj-L.a[0][0]*Fi)/L.a[1][0];
		}
		long long ANS;
		if(N>=i){
			L=R.power(N-i);
		}
		else{
			L.a[0][0]=-1;L.a[0][1]=1;
			L.a[1][0]=1;L.a[1][1]=0;
			L=L.power(i-N);
		}
		ANS=Fi*L.a[0][0]+Fj*L.a[1][0];
		//cout<<ANS<<endl;
	}
return 0;
}








