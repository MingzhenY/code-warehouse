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
	char a[1000];
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
			d=C.a[i]<0;
			if(d) C.a[i]+=10;
		}
		while(C.len>1&&!C.a[C.len-1]) C.len--;
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
Int f[10][82];
int main(void)
{freopen("1353.txt","r",stdin); 
	f[0][0]=1;
	for(int i=0;i<9;i++){
		for(int j=0;j<=81;j++){
			for(int k=0;k<=9&&j+k<=81;k++){
				f[i+1][j+k]+=f[i][j];
			}
		}
	}
	int S;
	cin>>S;if(S==1) f[9][S]+=Int(1);
	f[9][S].show();
	cout<<endl;
return 0;
}








