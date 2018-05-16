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
#define ULL unsigned long long
using namespace std;
const unsigned long long C=(1LL <<30)-1;
ULL N,K,M;
struct Int{//做 mod M 的加法跟乘法 ( 1<= M <= 10^18) 
	ULL a,b;
	Int():a(0),b(0){}
	Int(ULL k){*this=k;}
	Int operator=(ULL k){
		b=k&C;a=k>>30;
		return *this;
	}
	Int operator+(const Int B)const{
		ULL D;
		D=(a+B.a)<<30;
		D+=b+B.b;
		return Int(D%M);
	}
	Int operator*(const Int B)const{
		ULL D1,D2;
		D1=(a*B.a)%M;D2=(a*B.b+b*B.a)%M;
		//OUT2(a*B.a,D1);
		for(int i=0;i<15;++i){D1<<=4;D1%=M;}
		for(int i=0;i<7;++i){D2<<=4;D2%=M;}
		//OUT3(D1,D2,(b*B.b)%M);
		return Int((D1+(D2<<2)+b*B.b)%M);
	}
	ULL get(){return (a<<30)+b;}
};
struct A{
	Int a[2][2];
	A operator*(const A B)const{
		A D;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					D.a[i][j]=D.a[i][j]+a[i][k]*B.a[k][j];
				}
			}
		}
		return D;
	}
	A power(long long k){
		A D;if(k <0) return D;
		if(k==0){D.a[0][0]=1;D.a[1][1]=1;D.a[0][1]=0;D.a[1][0]=0;return D;}
		if(k==1){return *this;}
		D=power(k>>1);
		if(k&1) return *this*D*D;
		else return D*D;
	}
	void show(){
		printf("%I64d %I64d\n%I64d %I64d\n",a[0][0].get(),a[0][1].get(),a[1][0].get(),a[1][1].get());
	}
};
int main(void)
{freopen("1013.txt","r",stdin); 
	while(cin>>N>>K>>M){
		A D;Int T=(K-1)%M;
		D.a[0][0]=0;D.a[0][1]=T;
		D.a[1][0]=1;D.a[1][1]=T;
		D=D.power(N-1);
		Int ANS=T*(D.a[1][0]+D.a[1][1]);
		cout<<ANS.get()<<endl;
	}
return 0;
}








