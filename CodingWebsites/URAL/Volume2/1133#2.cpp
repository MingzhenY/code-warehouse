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

long long i,Fi,j,Fj,N;
int main(void)
{freopen("1133.txt","r",stdin); 
	while(cin>>i>>Fi>>j>>Fj>>N){
		if(i>j){
			long long t=i;i=j;j=t;
			t=Fi;Fi=Fj;	Fj=t;
		}
		
		int Flag;
		long long L=-2000000000,R=2000000000,M,FI,FI_;
		
		begin:
			M=(L+R)>>1; 
			FI=Fi,FI_=M;
			Flag=0;
			for(int k=i;k<j;k++){
				long long FII=FI+FI_;
				if(FII>2000000000) Flag=1;
				if(FII<-2000000000) Flag=-1;
				if(Flag) break;
				FI=FI_;FI_=FII;
			}
			if(Flag){
				if(Flag>0) R=M;
				else L=M;
			}
			else{
				if(FI<Fj) {
					L=M;goto begin;
				}
				if(FI>Fj){
					R=M;goto begin;
				}
			}
		//¼ÆËã
		long long a,b,c,ANS;
		if(N>=i){
			a=Fi;b=M;
			for(int k=i;k<N;k++){
				c=a+b;
				a=b;
				b=c;
			}
			ANS=a;
		} 
		else{
			a=Fi;b=M-a;
			for(int k=i;k>N;k--){
				c=a-b;
				a=b;
				b=c;
			}
			ANS=a;
		}
		
		cout<<ANS<<endl;
	}
return 0;
}








