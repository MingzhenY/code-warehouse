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

int N;string str;
int check(int i){//以i为中心的最大值 
	int ANS=1;
	int L=i-1,R=i+1;
	while(L>=0&&R<N){
		if(str[L]==str[R]){
			L--,R++;ANS+=2;
		}
		else{
			break;
		}
	}
	return ANS;
}
int check2(int i){//以i和i+1为中心的最大值
	int ANS=0;
	int L=i,R=i+1;
	while(L>=0&&R<N){
		if(str[L]==str[R]){
			L--,R++;ANS+=2;
		}
		else{
			break;
		}
	}
	return ANS;
}
int main(void)
{freopen("1297.txt","r",stdin); 
	while(cin>>str){
		N=str.length();
		int ANS1=0,ANS2=0,I1=-1,I2=-1;
		For(i,N){
			//if(str[i]=='n') OUT3(i,check(i),check2(i));
			int D=check(i);
			if(D>ANS1) {
				ANS1=D,I1=i;
			}
			D=check2(i);
			if(D>ANS2){
				ANS2=D;I2=i;
			}
		}
		int L,ANS;
		if(ANS1>ANS2){
			L=I1-ANS1/2;ANS=ANS1;
		}
		else{
			L=I2-ANS2/2+1;ANS=ANS2;
		}
		for(int i=L;i<L+ANS;i++){
			printf("%c",str[i]);
		}
		cout<<endl;
	}
return 0;
}








