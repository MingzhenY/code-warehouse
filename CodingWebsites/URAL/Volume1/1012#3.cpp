#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 100
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct bign{
	char num[1000];
	int n;
	bign operator +(bign &B){
		bign C;
		int d=0;
		for(int i=B.n;i<max(n,B.n);i++) B.num[i]=0;
		for(int i=n;i<max(n,B.n);i++) num[i]=0;
		For(i,max(n,B.n)){
			C.num[i]=(num[i]+B.num[i]+d)%10;
			d=(num[i]+B.num[i]+d)/10;
		}
		C.n=max(n,B.n)+1;
		C.num[max(n,B.n)]=d;
		while(!C.num[C.n-1]) C.n--;
		return C;
	}
	bign operator =(int k){
		n=0;
		while(k>0) num[n++]=k%10,k/=10;
	}
	void show(){
		for(int i=n-1;i>=0;i--){
			printf("%c",num[i]+48);
		}
		printf("\n");
	}
	bool operator <(const bign &B)const{
		int N=max(n,B.n);
		for(int i=N-1;i>=0;i--){
			if(num[i]==B.num[i]) continue;
			if(num[i]<B.num[i]) return 1;
			else return 0;
		}
		return 0;
	}
	bool operator ==(const bign &B)const{
		if(n!=B.n) return 0;
		For(i,n) if(num[i]!=B.num[i]) return 0;
		return 1;
	}
	bool operator <=(const bign &B)const{
		return *this<B||*this==B;
	}
};
bign Z[181];
bign NZ[181];

int main(void)
{freopen("1012.txt","r",stdin); 	
	int N,K;
	while(cin>>N>>K){
		Z[1]=1;NZ[1]=K-1;
	for(int i=2;i<=N;i++){
		Z[i]=NZ[i-1];
		NZ[i]=0;
		For(j,K-1) NZ[i]=NZ[i]+Z[i-1]+NZ[i-1];
	}
	NZ[N].show();
	}
return 0;
}








