#include <iostream>
#include <cstdio>
#include <cmath>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;

long long cnt1,cnt2,x,y;
bool F(long long K){
	return (K-K/(x*y)>=cnt1+cnt2)&&(K-K/y>=cnt2)&&(K-K/x>=cnt1);
}
int main(void)
{
	freopen("B.txt","r",stdin); 
	while(cin>>cnt1>>cnt2>>x>>y){
		long long L=0,R=1000000000,M;R=R*R;
		//×ó¿ªÓÒ±Õ 
		begin:
			if(L+1==R) goto end;
			M=(L+R)>>1;
			if(F(M)) R=M;
			else L=M; 
			goto begin;
		end:
		cout<<R <<endl;
	}
	
	
return 0;
}
