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
struct Int{
	char a[200];
	int len;
	Int(int k){*this=k;}
	Int(){*this=0;}
	void operator =(int k){
		if(!k){len=1;a[0]=0;return;}
		len=0;
		while(k) a[len++]=k%10,k/=10;
	}
	void operator =(string k){
		len=k.length();
		for(int i=0;i<len;i++) {
			a[i]=k[len-i-1]-48;
		}
	}
	Int operator +(Int &B){
		Int C;C.len=len>B.len?len:B.len;
		for(int i=len;i<C.len;i++) a[i]=0;
		for(int i=B.len;i<C.len;i++)B.a[i]=0;
		int d=0;
		for(int i=0;i<C.len;i++){
			C.a[i]=a[i]+B.a[i]+d;
			d=C.a[i]/10;
			C.a[i]%=10;
		}
		if(d) C.a[C.len++]=d;
		return C;
	}
	Int operator +=(Int B){
		*this=*this+B;
		return *this;
	}
	Int operator -(Int &B){
		Int C;C.len=len;
		for(int i=B.len;i<C.len;i++)B.a[i]=0;
		int d=0;
		for(int i=0;i<C.len;i++){
			C.a[i]=a[i]-B.a[i]-d;
			d=0;
			while(C.a[i]<0) d++,C.a[i]+=10;
		}
		while(C.len>0&&!C.a[C.len-1]) C.len--;
		if(C.len==0) C=0;
		return C;
	}
	bool operator>=(Int B){
		if(len>B.len) return 1;
		if(len<B.len) return 0;
		for(int i=len-1;i>=0;i--){
			if(a[i]>B.a[i]) return 1;
			if(a[i]<B.a[i]) return 0;
		}
		return 1;
	}
	void show(){
		for(int i=len-1;i>=0;i--) printf("%d",a[i]);
	}
};
Int f[101][50];
int s[101];
int L,M,K;
string N;Int NN;
void F(Int k){
	int CurR=0;
	FOR(i,L){
		s[i]=1;
		while(k>=f[L-i][(K-(CurR+s[i])%K)%K]){
			k=k-f[L-i][(K-(CurR+s[i])%K)%K];
			s[i]++;
			if(s[i]==M) break;
		}
		CurR+=s[i];
		CurR%=K;
	}
	FOR(i,L){
		printf("%d",s[i]);
		if(i==L) printf("\n");
		else printf(" ");
	}	
}
int main(void)
{freopen("1310.txt","r",stdin); 
	while(cin>>L>>M>>K>>N){
		For(i,101) For(j,50) f[i][j]=0;
		f[0][0]=1;
		For(i,L){
			For(j,K){
				FOR(k,M){
					f[i+1][(j+k)%K]+=f[i][j];
				}
			}
		}
		NN=N;
		F(NN);
	}
return 0;
}








