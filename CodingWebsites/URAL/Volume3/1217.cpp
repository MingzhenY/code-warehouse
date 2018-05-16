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
#define maxn 1000
struct BigN{
	char a[maxn];
	int len;
	BigN(){memset(a,0,sizeof(a));len=1;}
	BigN(int n){
		*this=n;
	}
	BigN operator+(BigN&B){
		BigN C;int n=max(len,B.len);
		for(int i=len;i<n;i++) a[i]=0;
		for(int i=B.len;i<n;i++)B.a[i]=0;
		int d=0;
		for(int i=0;i<n;i++){
			char D=a[i]+B.a[i]+d;
			C.a[i]=D%10;
			d=D/10;
		}
		if(d) {
			C.len=n+1;C.a[n]=d;
		}
		else{
			C.len=n;
		}
		return C;
	}
	BigN operator *(BigN B){
		BigN ANS=0;
		for(int i=0;i<len;i++){
			for(int j=0;j<B.len;j++){
				BigN temp=a[i]*B.a[j];
				temp.left(i+j);
				ANS=ANS+temp;
			}
		}
		return ANS;
	}
	void left(int k){
		len+=k;
		for(int i=len-1;i>=k;i--) a[i]=a[i-k];
		for(int i=0;i<k;i++) a[i]=0;
	}
	BigN operator=(int B){
		len=!B;a[0]=0;
		while(B) a[len++]=B%10,B/=10;
		return *this;
	}
	void show(){
		for(int i=len-1;i>=0;i--){
			printf("%c",a[i]+48);
		}
	}
};
BigN F[6][46];
int N;
BigN f(int t){
	BigN ANS;
	for(int i=0;i<=t*9;i++){
		BigN C=F[t][i]*F[t][i];
		ANS=ANS+C;
	}
	return ANS;
}
BigN Func(int t){
	return f(t/2)*f((t+1)/2);
}
int main(void)
{freopen("1217.txt","r",stdin); 
	F[0][0]=1;
	for(int i=1;i<6;i++){
		for(int j=0;j<=i*9;j++){
			for(int k=0;k<=9;k++){
				if(k>j) break;
				F[i][j]=F[i][j]+F[i-1][j-k];
			}
		}
	}
	while(cin>>N){
		BigN ANS=Func(N>>1);
		ANS.show();
		cout<<endl;
	}
return 0;
}








